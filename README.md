# Cramersche Regel
Hier ein mal die Cramersche Regel in C programmiert und via .mex-File in Octave getestet. Dazugehörig noch Laufzeittests im Vergleich zur A\b-Funktion von Octave. Die Laufzeittests beinhalten Matrizen von 1x1 bishin zu 7x7. Danach ergaben weiter Tests keinen Sinn mehr.
<br>
<br>
Für das Lösen von Matrizen habe ich meinen Laplace-Entwicklungssatz verwendet:<br>
https://github.com/JoeKL/Laplace-Entwicklungssatz<br>
<br>
<br>

| dim | Zeit A\b in Sek|Zeit cramer in Sek|
|-----|----------------|------------------|
| 1x1 |       0.0102811|         0.0871289|
| 2x2 |       0.0675809|          0.084693|
| 3x3 |       0.0672929|            0.0857|
| 4x4 |       0.0730109|         0.0923591|
| 5x5 |       0.0853658|          0.147374|
| 6x6 |       0.0939429|          0.524941|
| 7x7 |       0.0979412|           3.55988|

<br>
<img src="https://github.com/JoeKL/Cramersche-Regel/blob/master/cramer/gg%C3%83%C2%BC.png" height="500"> <br>
Hier dann noch ein mal die Gegenüberstellung als Graphen in einem logarithmischen Koordinatensystem. Die Cramer-Implementierung ist hier als Blau und die Octave-Implementierung als Rot zu sehen. Es fällt auf, dass die Laufzeit beider Algorithmen bis 4x4 praktisch gleich ist. 5x5 weißt schon leichte Abweichungen auf und ab 6x6 ist die höhere Komplexität meiner Cramer-Implementierung zu spüren.
Aber auch hier ist zu sehen, dass für unsere Aufgabe (5x5 Matrix) die Laufzeit der Cramer-Implementierung vollkommen ausreicht.
 
<br>

Mein System:<br>
  Systemmodell: Dell XPS 15 9560<br>
  OS: Windows 10 Home 64-Bit-Version (10.0, Build 17763)<br>
  CPU: Intel Core i5 7300HQ @ 2.50GHz (4 CPUs)<br>
  Speicher: 8192MB RAM
