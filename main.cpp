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

    //std::cout << nota->getText() << std::endl;
    //nota1->lockNote();
    std::cout << "stato nota : " << nota1->isLocked() << std::endl;
    //nota1->UnLockNote();
    nota1->modifyText("nuovo testo");
    //std::cout << nota->getText();


    auto *collection = new Collection("CollezioneProva", 2);
    Display count(collection);
    collection->addNote(*nota1);
    collection->addNote(*nota2);

    collection->readNotes();
    //collection->removeNote(*nota1);
    collection->removeNote(*nota2);
    collection->updateNote("title", "newTitle", "newText");
    collection->readNotes();

    return 0;

}
