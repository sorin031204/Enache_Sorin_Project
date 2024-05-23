#include <iostream>
#include <ncurses.h>

#include "Collection.h"
//Classi che rappresentano note (es. Bear / Evernote). Ogni nota è composta da titolo e testo, può essere bloccata per evitarne
//cancellazione/modifica e fa parte di una collezione specificata con nome.
//Può anche far parte di una collezione di note importanti oltre che di una collezione specifica.
// Usare Observer per indicare quante note stanno in una collezione.
//Reformat Code  press ⌘Сmd ⌥Opt L.

int main() {
    Note *nota = new Note("title" , "testo");
    std::cout << nota->getText();
    nota->LockNote();
    nota->UnLockNote();
    std::cout << nota->StatusNote();

    return 0;
}
