#include <iostream>
#include "Display.h"

//Classi che rappresentano note (es. Bear / Evernote). Ogni nota è composta da titolo e testo, può essere bloccata per evitarne
//cancellazione/modifica e fa parte di una collezione specificata con nome.
//Può anche far parte di una collezione di note importanti oltre che di una collezione specifica.
// Usare Observer per indicare quante note stanno in una collezione.
//Reformat Code  press ⌘Сmd ⌥Opt L.

int main() {
    Note *nota1 = new Note("title", "text");
    Note *nota2 = new Note("titolo", "testo");

    auto *collection = new Collection("CollezioneProva", 2);
    Display count(collection);
    collection->addNote(*nota1);
    collection->addNote(*nota2);

    //nota1->lockNote();
    collection->readNotes();
    collection->removeNote(*nota2);

    collection->updateNote("title", "newTitle", "newText");
    collection->readNotes();

    return 0;

}
