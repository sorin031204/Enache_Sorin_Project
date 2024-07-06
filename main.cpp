#include <iostream>
#include "Display.h"

//Classi che rappresentano note (es. Bear / Evernote). Ogni nota è composta da titolo e testo, può essere bloccata per evitarne
//cancellazione/modifica e fa parte di una collezione specificata con nome.
//Può anche far parte di una collezione di note importanti oltre che di una collezione specifica.
// Usare Observer per indicare quante note stanno in una collezione.
//Reformat Code  press ⌘Сmd ⌥Opt L.

int main() {
    Note *nota = new Note("title", "text");
    Note *nota2 = new Note("titolo", "testo");

    //std::cout << nota->getText() << std::endl;
    //nota->LockNote();
    //std::cout << nota->StatusNote() << std::endl;
    //nota->UnLockNote();
    //nota->modifyText(*nota, "nuovo testo");
    //std::cout << nota->getText();


    Collection *collection = new Collection("CollezioneProva", 2);
    Display count(collection);
    collection->AddNote(*nota);
    collection->AddNote(*nota2);

    collection->ReadNotes();
    collection->RemoveNote(*nota);
    std::cout << "spazio" << std::endl;
    collection->ReadNotes();


    return 0;
}
