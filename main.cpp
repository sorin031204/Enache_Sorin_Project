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
    nota1->LockNote();
    std::cout << "stato nota" << nota1->StatusNote() << std::endl;
    //nota->UnLockNote();
    //nota->modifyText(*nota, "nuovo testo");
    //std::cout << nota->getText();

    auto *collection = new Collection("CollezioneProva", 2);
    Display count(collection);
    collection->AddNote(*nota1);
    collection->AddNote(*nota2);

    collection->ReadNotes();
    collection->RemoveNote(*nota1);
    collection->RemoveNote(*nota2);


    return 0;
}
