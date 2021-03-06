# TerenEU07
Program tworzy, z danych SRTM lub NMT100, oraz scenerii z edytora Rainsted,
teren dla realistycznych scenerii symulatora MaSzyna EU07,
o ile sceneria z edytora Rainsted posiada profil pionowy pod torami.
Ponadto teren może zostać zalesiony przypadkowo wylosowanym drzewem na jeden
trójkąt terenu, o ile wcześniej skopiowano katalog l61_plants (można go
znaleźć w katalogu textures należącym do paczki symulatora) wraz ze
wszystkimi lub wybranymi teksturami drzew, do katalogu z programem terenEU07.
Dodana została także opcja generowania terenu niedopasowanego do torów.

Aktualnie program automatycznie korzysta z danych SRTM 3 arc sec jeśli
w danym miejscu w modelu SRTM 1 arc sec brakuje danych. Wadą tej metody
jest to, że program musi odczytać oba rodzaje plików, co trwa nieco
dłużej, oraz zauważalne gołym okiem przejście w miejcu gdzie łączy się
teren wygenerowany z SRTM 1 arc sec z SERM 3 arc sec.


Niektóre sposoby na rozwiązania problemów wykorzystane w tym programie
podpowiedział kolega "Ra", za co dziękuję.


Znane problemy: Normalne wierzchołków trójkątów na łączeniu terenu z profilem
są źle policzone.


Krótka instrukcja obsługi programu:

W katalogu z programem powinny być:

1. Plik ze scenerią (aktualnie na stałe zaszyta nazwa "EXPORT.SCN",
bo taki plik domyślnie tworzy edytor Rainsted).

2. Przynajmniej a), a najlepiej a) oraz b), lub c):

a) Katalog o nazwie SRTM, a w nim pliki .hgt z obszarem pokrywającym teren
scenerii.

b) Katalog o nazwie DTED a w nim katalog DEM oraz HEM. W katalogu DEM
pliki z danymi wysokościowymi .dt2. W katalogu HEM pliki .dt2 z mapą błędów.
Pliki oczywiście powinny pokrywać teren scenerii.

c) Katalog NMT100, a w nim pliki .txt z obszarem pokrywającym teren scenerii.

3. W tym samym (najlepiej) lub innym katalogu możliwość skompilowania
i uruchomienia darmowego programu "Triangle", który z podanych punktów tworzy trójkąty.


Kompilacja programu TerenEU07:
g++ -std=c++11 -O3 -o terenEU07 main.cpp


Aby uzyskać teren w formacie symulatora MaSzyna EU07 należy
uruchomić program TerenEU07 i wybrać opcję nr 1.
To utworzy nam plik wierzcholkiprofil.node. Następnie 
uruchamiamy ponownie i wybieramy opcję nr 2 lub 5 w zależności
od tego, jakie dane modelu wysokościowego wykorzystujemy. Powstanie plik 
wierzcholki150.node, który trzeba potraktować programem Triangle:
./triangle -YV [sciezka_do_jesli_inny_katalog]wierzcholki150.node.
Utworzonych zostanie kilka plików, ale ważny jest wierzcholki150.1.ele.
Ponownie uruchamiamy program TerenEU7, wybieramy opcję nr 3, lub 6
w zależności od tego jakie dane modelu wysokościowego wykorzystujemy,
i otrzymamy plik wierzcholki1000.node. Ten też przetwarzamy programem Triangle,
podobnie jak poprzedni ./triangle -YV wierzcholki1000.node. Powstaną nowe pliki,
a w nim ten istotny dla nas wierzcholki1000.1.ele. Ostatni etap,
uruchamiamy program TerenEU07 i wybieramy opcję nr 4.
W ten sposób otrzymamy plik(i) terenX.scm (gdzie X to nr od 1),
który można już użyć w symulatorze jako teren.

Kilka uwag:

1. Edytor Rainsted, pomimo moich sugestii, tworzy plik tekstowy
EXPORT.SCN z końcami linii w formacie Microsoft, a więc jeśli
ktoś zamierza kompilować i używac go pod systemem unixowym należy
ten plik przekonwertować na format unixowy. Np. w programie vi
komendą ":set ff=unix".

2. W edytorze Rainsted na obecną chwilę nie da się w prosty sposób
wykonać rowow profilu pod torami przy użyciu danych modelu NMT100,
dlatego też generowanie całego terenu z danych NMT100 mija się z celem.

3. Problemem może być odpowiednie zszycie terenu między profilami
biegnacymi obok siebie. Ze względu na problemy z triangulacją
w tych miejscach, trzeba to solidnie wykonać w programie Rainsted.

4. Program działa nieco szybciej w systemie linux niż w MS Windows.

5. Teren na łączeniu SRTM 1 arc sec z SRTM 3 arc sec na razie
jeszcze nie wygląda najlepiej.

Symulator MaSzyna EU07 można pobrać ze strony: http://eu07.pl/.

Edytor Rainsted znajduje się w paczce z symulatorem. Strona projektu 
to http://rainsted.com/pl/.

Program Triangle dostepny pod adresem:
http://www.cs.cmu.edu/~quake/triangle.html.

Dane SRTM 3 arc sec w formacie HGT można pobrać pod adresem:
http://dds.cr.usgs.gov/srtm/version2_1/SRTM3/Eurasia/ (nowsza wersja),
lub: http://netgis.geo.uw.edu.pl/srtm/Poland/ (starsza wersja, i serwer
ostatnio nie działa).

Dane SRTM 1 arc sec można znaleźć pod adresem:
https://centaurus.caf.dlr.de:8443/eoweb-ng/template/default/welcome/entryPage.vm
(należy się zarejestrować i kliknąć w przycisk "SRTM Data Download").

Dane NMT100 można pobrać z tego adresu:
http://www.codgik.gov.pl/index.php/darmowe-dane/nmt-100.html
