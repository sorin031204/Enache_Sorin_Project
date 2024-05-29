#include <iostream>
#include "vector"

#include "Collection.h"
//Classi che rappresentano note (es. Bear / Evernote). Ogni nota è composta da titolo e testo, può essere bloccata per evitarne
//cancellazione/modifica e fa parte di una collezione specificata con nome.
//Può anche far parte di una collezione di note importanti oltre che di una collezione specifica.
// Usare Observer per indicare quante note stanno in una collezione.
//Reformat Code  press ⌘Сmd ⌥Opt L.

int main() {
    Note *nota = new Note("title", "text");
    Note *nota2 = new Note("titolo", "testo");
    //std::cout << nota->getText() << std::endl;
    nota->LockNote();
    std::cout << nota->StatusNote() << std::endl;
    //nota->UnLockNote();
    //nota->modifyText(*nota, "nuovo testo");
    //std::cout << nota->getText();


    Collection *collection = new Collection("CollezioneProva" , 1);
    //collection->AddNote( *nota);
    collection->AddNote( *nota2);

    collection->ReadNote(*nota);
    delete nota;
    collection->ReadNote(*nota);

    return 0;
}
