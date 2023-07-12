Prezenta aplicatie doreste simularea unui editor text. Interfata este una simpla utlizand linia de comanda pentru comanda utilizatorului. Dupa fiecare operatie se afiseaza meniul principal.
Pentru a fi siguri introducerea corecta a unui numar s-a utlizat o functie int_safeRead() a carei scop este sa curete orice caracter nedorit introdus de la tastura cand este crucial unu numar.

La alegerea unei optiuni implementate se va afisa un submeniu aferent. In versiunea actuala sunt disponibile

1.  INSERT(text, pos) adauga textul incepand cu pozitia pos(numerotarea incepe de la 1). Scrieti textul ce se doreste a fi introdus urmat de ENTER, dupa pozitia si iar ENTER.
	Deorece nu stim lungimea textului initial se utilizeaza un string ce este transformat la sir de caractere pentru a corespunde cerintei.
	Metoda de Inserare parseaza textul primit ca parametru prin intermediul metodei cu strtok si dupa il insereaza in text.

2.  INSERT(text, pos) adauga textul incepand cu pozitia pos(numerotarea incepe de la 1). Scrieti textul ce se doreste a fi introdus urmat de ENTER, dupa pozitia si iar ENTER.
	O evolutie a primei optiuni ce permite introducerea pe o pozitie arbitrara din text. Anumite cazuri limita sunt rezolvate prin apelarea primei optiuni

3.  DELETE(k, pos) sterge k cuvinte incepand cu pozitia pos(numerotarea incepe de la 1). Scrieti numarul de cuvinte ce se doreste sters urmat de ENTER, dupa pozitia si iar ENTER.
	Asigura eliminearea corecta a unui numar de cuvinte incepand cu o pozitie data. Eliminarea de la prima pozitie este cea mai dificila avand in vedere ca sa modifica capul listei.

4.  DELETE_all(word) sterge toate aparitiile unui cuvant. Cuvantul se va introduce si dupa ENTER
	Asigura stergerea tuturor instantelor unui cuvant. De asemenea curata zonele de memorie ce le contine.

5.  DELETE_TEXT() sterge TOATE cuvintele
	O metoda complet destructiva. Asigura eliberarea zonelor de memorie ocupate de cuvinte din text.

6.  FIND(word) cauta un cuvant si returneaza poziitiile si numarul de cuvinte. Cuvantul se va introduce si dupa ENTER
	Permite cautarea unui cuvant anume din text. Chiar si in cazul in care nu exista se va afisa un mesaj corespunzator

7.  REPLACE(word1, word2) inlocuieste word1 cu word2. Se va introduce primul cuvant, ENTER, cuvantul ce il va inlocui si ENTER.
	Permite inlocuirea totala a unui cuvant. O atentie sporita a fost acordata cand se modifica primul element din text, fiind necesara modificarea unui element privat din obiect

8.  DISPLAY afiseaza textul
	Se explica de la sine.

9.  UNDO (implementata partial) se revine la starea anterioara
	In versiunea actuala se indica ce operatie s-ar efectua + trateaza eroarea.

10. REDO (implementata partial) se reface ultima operatie supusa UNDO
	In versiunea actuala se indica ce operatie s-ar efectua + trateaza eroarea.

Erorile sunt semnalate prin mesaje justificative, tratarea lor permite continuarea programului cu alte comenzi valide.

Legat de functiile de UNDO/REDO am considerat stiva drept o structura utila. Astfel la efectuarea oricarei operatii ce modifica textul se introduce in stiva de undo un element continand ID-ul operatiei si eventualii parametrii cu care ar fi fost implementata.
O atentie speciala necesita anularea stergerii complete, deoarece va fi nevoie sa scoatem din stiva toate elementele pana la o alta comanda DELETE. Aceasta operatie ar trebui sa fie non-distructiva la stiva (posibil utilizarea inca unei stive pentru a "turna" call-urile dintr-una in alta).
Scoaterea unui element din stiva de UNDO se va pune in cea de REDO. Stergerea stivei de REDO se efectueza in momentul efectuarii unei operatii destructive asupra textului.

Utilizarea paradigmei de programare orientata pe obiecte este justificata de necesitatea unui obiect asupra caruia se efectueaza operatii destructive si a carui return este obiectul in sine. Astfel intregul text este o lista de cuvinte, cu acces doar la primul cuvant prin metoda getCap(), pentru restul e necesara o parcurgere a textului.

Consider ca cel mai dificil lucru a fost lucrul cu siruri de caractere in forma lor dinamica. Eficienta de memorie nu cred ca justifica obfuscarea excesiva a codului. De aceea au fost necesare diverse bypass-uri legate de lungimea necunoscuta de intrare sau copii auxiliare pentru a evita pierderea originalului.
Codul a devenit mai instabil prin acces nejustificat la memorie, lucru care a necesitat lungi sedinte de debugg.

!Aplicatia a fost proiecta pentru sistemele de operare de la windows. Nu garantez compatibilitate cross-platform, deoarece pentru stergerea terminalului am folosit libraria "windows.h", necesara curatarii terminalului.

Software offered under the MIT license, and not limited to 
"The software is provided AS IS, without warranty of any kind, express or implied"

Andrei Valeriu Cosa,
AC_1204B