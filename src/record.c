#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <record.h>

const char* names[] = {
    "Yannis", "Christofos", "Sofia", "Marianna", "Vagelis", "Maria", "Iosif", "Dionisis", "Konstantina",
    "Theofilos", "Giorgos", "Dimitris", "Eleni", "Nikos", "Panagiotis", "Despina", "Apostolos", "Eirini",
    "Antonis", "Katerina", "Alexandros", "Anastasia", "Leonidas", "Paraskevi", "Petros", "Eva", "Ioannis",
    "Stavroula", "Spyros", "Elisavet", "Andreas", "Efi", "Themis", "Aspasia", "Kostas", "Marina", "Giannis",
    "Vasiliki", "Dimitra", "Stefanos", "Rania", "Nikolaos", "Ioulia", "Charalambos", "Chrysa", "Thanasis",
    "Georgia", "Michalis", "Zoi", "Konstantinos", "Daphne", "Pavlos", "Xristina", "Kyriakos", "Loukia",
    "Sotiris", "Kalliopi", "Efthimis", "Fotini", "Alexandra", "Giorgis", "Danae", "Vasileios", "Magda",
    "Eleni", "Manolis", "Anna", "Dionysios", "Parthena", "Dimitroula", "Georgios", "Argyro", "Aggelos",
    "Angeliki", "Ioanna", "Christina", "Antonia", "Vassilis", "Ifigeneia", "Xenophon", "Eleftheria",
    "Achilleas", "Polina", "Nefeli", "Ioannis", "Melina", "Christos", "Olga", "Aikaterini", "Athanasios",
    "Irini", "Nikola", "Dora", "Elektra", "Rafail", "Klio", "Thalia", "Anastasios", "Violeta", "Efstathios"
};

const char* surnames[] = {
    "Ioannidis", "Svingos", "Karvounari", "Rezkalla", "Nikolopoulos", "Berreta", "Koronis", "Gaitanis", 
    "Oikonomou", "Mailis", "Michas", "Halatsis", "Papadopoulos", "Pappas", "Georgiou", "Nikolaidis", "Katsaros",
    "Zervas", "Livanos", "Makris", "Papageorgiou", "Sarantopoulos", "Konstantinidis", "Antonopoulos", "Petrakis",
    "Apostolou", "Daskalakis", "Manolopoulos", "Papadakis", "Stamatakis", "Sotiriou", "Economou", "Tsilimparis",
    "Vlachos", "Mavridis", "Samaras", "Zachariadis", "Makridis", "Stavropoulos", "Diamantopoulos", "Matsoukas",
    "Fotopoulos", "Papantonis", "Gkikas", "Vourlis", "Apostolopoulos", "Papaioannou", "Sidiropoulos", "Maragos",
    "Gkotsis", "Papazoglou", "Antoniou", "Vasilakis", "Papoutsi", "Papageorgiou", "Papadellis", "Papazachariou",
    "Gkouskos", "Zachariou", "Paraskevopoulos", "Papadimitriou", "Stavrou", "Lamprou", "Kostopoulos", "Fotinakis",
    "Theodorou", "Gkogkas", "Papazisis", "Laskaris", "Gkizas", "Dellis", "Tsigaridas", "Papamichael", "Trikalinos",
    "Zafiriadis", "Kalliris", "Nastou", "Tsekouras", "Makrakis", "Tsimiklis", "Papanikolaou", "Saroglou", "Papaloukas"
};

const char* cities[] = {
    "Athens", "Thessaloniki", "Patras", "Heraklion", "Larissa", "Volos", "Ioannina", "Komotini", "Rhodes", "Chania",
    "Kavala", "Serres", "Drama", "Veria", "Trikala", "Lamia", "Kozani", "Alexandroupoli", "Katerini", "Kalamata",
    "Mytilene", "Chalcis", "Sparta", "Kos", "Pyrgos", "Argos", "Livadeia", "Preveza", "Amaliada", "Karpenisi",
    "Xanthi", "Karditsa", "Ptolemaida", "Grevena", "Corfu", "Florina", "Nafplio", "Edessa", "Rethymno", "Kalymnos",
    "Naxos", "Arta", "Korinthos", "Chios", "Syros", "Kilkis", "Thiva", "Piraeus", "Eleusina", "Chalkida",
    "Peristeri", "Marousi", "Kallithea", "Acharnes", "Nea Ionia", "Ilioupoli", "Vrilissia", "Papagou", "Glyfada",
    "Kifisia", "Kalamaria", "Thermaikos", "Serres", "Drama", "Agrinio", "Chalcis", "Myrina", "Gaziosmanpasa",
    "Usak", "SanFran", "LosAngeles", "NewYork", "Tokyo", "London", "Paris", "Berlin", "Madrid", "Rome",
    "Sydney", "Toronto", "Dubai", "Mumbai", "Beijing", "Moscow", "Cairo", "RioDeJaneiro", "BuenosAires", "MexicoCity"
};

static int id = 0;
//typedef struct Record {
//    char name[15];
//    char surname[15];
//    char city[15];
//    int id;
//    char delimiter[2];
//} Record;
Record randomRecord(){
    Record record;
    // create a record
    record.id = id++;
    int r = rand() % 100;
    memset(record.name,0,15);
    memset(record.surname,0,15);
    memset(record.city,0,15);
    memset(record.delimiter,0,2);

    memcpy(record.name, names[r], strlen(names[r]) + 1);
    r = rand() % 82;    
    memcpy(record.surname, surnames[r], strlen(surnames[r]) + 1);
    r = rand() % 50;
    memcpy(record.city, cities[r], strlen(cities[r]) + 1);
    memcpy(record.delimiter, "\n", strlen("\n") + 1);
    return record;
}

void printRecord(Record record){
    char name[16]= {0};
    char surname[16]= {0};
    char city[16]= {0};
    strncpy(name,record.name,15);
    strncpy(surname,record.surname,15);
    strncpy(city,record.city,15);
    printf("%d,%s,%s,%s%s",record.id,name,surname,city,record.delimiter);
}



