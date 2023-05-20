# Nagyhazi-naptar
Naptrarrendszer prog2 nagyhazi;

Kocsis Dávid
DJADP1
Házi FeladatA programozás alapjai 2
Dokumentáció
2023. Április 11.
Kocsis Dávid
DJADP1

1. Feladat

Naptár osztály
Készítsen naptár tárolására osztályt! Az osztály legyen képes tetszőleges naptári napot
lefoglalni, és le lehessen kérdezni, hogy eddig milyen napok foglaltak, valamint egy adott nap
foglalt-e vagy szabad (szabad, ha nem foglalt). Számítsa ki, hogy egy adott naptári nap
milyen napra esik. Az osztály legyen képes két naptári nap összehasonlítására, eltelt napok
számának kiszámítására! Legyen lehetőség táblázatos formában éves, és havi naptár
nyomtatására! Valósítsa meg az összes értelmes műveletet operátor átdefiniálással (overload),
de nem kell ragaszkodni az összes operátor átdefiniálásához! Legyen az osztálynak iterátora
is!

2. Feladat Specifikáció:
A program egy fájlból olvassa be a kliens naptári adatait. A fájl (idopontok.txt) a foglalt
időpontok számával kezdődik, majd soronként az időpontok év-hónap-nap, a következő
sorban az időpont óra perctől óra percig (xx:yy-xx:yy formátumban), a következő sorban
a neve a programnak, a fajtája , utána a „hely” ,ez ismétlődik fájl vége jelig. A naptár
használata után kiírhatjuk a módositott naptári adatokat.
A kliens menüből választhat:

1. Naptár kiírtatása, a felhasználó választhat nap, hónap és év közül, ha napot választ,
meg kell adnia a dátumot, ha hónapot elég az évet és a hónapot, ha évet akkor csak
az évet.
2. Új időpont a naptárba, itt először meg kell adni a dátumot és az időpontot, ha még
szabad akkor kéri bemenetre a nevét, fajtáját és a helyét az időpontnak, ha
nemszabad, akkor kiírja az akkori időpont adatait, és ha szeretné felül írhatja őket.
3. Meglévő dátumok keresése valamelyik adat alapján. A felhasználó választhat hogy id,
időpont, név, típus, vagy hely alapján keres egy programot, a választott adat típus
alapján kilistázza a találatokat a program minden adattal együtt.
4. Időpont módosítása, a felhasználó id alapján kiválaszt egy időpontot és választhat az
adatok közül melyiket módosítja (az id nem módosítható, illetve ha az uj időpont
passzol egy másikéval, ugyan úgy viselkedik mint az új időpontnál).
5. Időpont törlése, ezt lehet akármelyik adat alapján.
6. Mentés fileba.
7. Exit.
