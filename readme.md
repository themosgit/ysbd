Σχεδιαστικές επιλογές:
Για το σορτάρισμα των records εντός των chunk χρησιμοποιήθηκε bubblesort.
Για τον εντοπισμό της ελάχιστης τιμής από τα bway chunks κατά το σορτάρισμα χρησιμοποιήθηκε η shouldswap της sort.c ως comparator.

Δυσλειτουργίες:
Δεν έχει παρατηρηθεί κάτι.

Σύνδεσμος:
Στο ακόλουθο σύνδεσμο υπάρχουν prompts για τις συναρτήσεις shouldswap, sort_Chunk και merge.
https://chat.openai.com/share/9f9b5a9c-e434-41d2-8a21-63e62199a062

Αλλαγές στις συναρτήσεις:
Στη shouldswap αντιστράφηκαν οι έλεγχοι για τον εντοπισμό της λεξικογραφικής σειράς των records. Το chatgpt αγνόησε επιδεικτικά την πρόταση "and return true if the comparison is positive" και αποφάσισε ότι πρέπει να κάνει ακριβώς το αντίθετο.
Από την sort_Chunk διατηρήθηκε η ιδέα του αλγορίθμου bubblesort, ωστόσο αλλάξανε τα κάτω όρια των i και j, για να προσαρμοστούν στις συναρτήσεις CHUNK (one based vs zero based). Τέλος, αντί να γίνεται απευθείας η σύγκριση των records, δημιουργήθηκαν δύο pointers σε records τα οποία αλλάζουν σε κάθε πέρασμα γιατί βοήθησε στο debugging (break points).
Από τη merge διατηρήθηκε η γενική ιδέα του αλγορίθμου για το merge, ωστόσο χρησιμοποιήθηκε μόνο ως έμπνευση για τον τελικό αλγόριθμο, ο οποίος παρουσιάζει σημαντικές διαφορές. Το chatgpt δεν έχει γνώση των βιβλιοθηκων BF και HP και για τον λόγο αυτό το merge που πρότεινε προσπαθεί να διαβάσει μόνο του τα αρχεία, με αποτέλεσμα να αντικατασταθεί το κομμάτι αυτό με κώδικα που χρησιμοποιεί τη βιβλιοθήκη HP και τις συναρτήσεις CHUNK. Τέλος, η σύγκριση των records μεταξύ τους πραγματοποιείται με τη συνάρτηση qsort της c, στην οποία ορίζεται ως comparator μία νέα συνάρτηση "compareRecords", η οποία αντικαταστάθηκε με τη shouldswap.
Διαπιστώθηκε ότι το chatgpt είναι περισσότερο χρήσιμο για να εμπνεύσει σε λογαριθμικά προβλήματα, παρά για να χρησιμοποιηθεί αυτούσιος ο κώδικας που παράγει, καθώς αποτυγχάνει να παράξει αξιόπιστα αποτελέσματα ακόμα και σε τετριμμένα προβλήματα (όπως της συνάρτησης shouldswap). 

Από παλαιότερο chat session με το chatgpt επιβεβαιώθηκε ότι δεν μπορεί να τεστάρει τον κώδικα που γράφει και μπορεί μόνο να κάνει το ακόλουθο: "...I can generate example code snippets or pseudocode to illustrate how certain programming concepts or algorithms work. These examples can be used as a starting point for writing actual code, but they may need to be adapted or modified depending on the specific programming language and application being used". Παρατίθεται το εν λόγω chat session: 
https://chat.openai.com/share/de43c748-a21c-4b91-97a4-264a9fd3ba10

