<!DOCTYPE html>
<html lang="fr">
<body>

<h1>Philosophers</h1>

<p><strong>Projet réalisé dans le cadre du cursus de l’école 42.</strong></p>

<hr>

<h2>Description</h2>

<p>
Philosophers est une implémentation du problème classique des
<strong>philosophes mangeurs</strong>.
Le but du projet est d’introduire les concepts de
<strong>programmation concurrente</strong>,
de <strong>synchronisation</strong> et de <strong>gestion des threads</strong>
en langage C.
</p>

<hr>

<h2>Objectifs pédagogiques</h2>

<ul>
  <li>Comprendre les problèmes de concurrence</li>
  <li>Manipuler les threads</li>
  <li>Utiliser des mutex pour éviter les data races</li>
  <li>Gérer précisément le temps d’exécution</li>
  <li>Éviter les deadlocks et les starvation</li>
</ul>

<hr>

<h2>Fonctionnement général</h2>

<ul>
  <li>Chaque philosophe est représenté par un thread</li>
  <li>Chaque fourchette est protégée par un mutex</li>
  <li>Un philosophe doit manger, dormir et penser</li>
  <li>La simulation s’arrête si un philosophe meurt ou si tous ont mangé suffisamment</li>
</ul>

<hr>

<h2>Contraintes du projet</h2>

<ul>
  <li>Langage : C</li>
  <li>Utilisation des threads (<code>pthread</code>)</li>
  <li>Synchronisation via mutex</li>
  <li>Pas de data race</li>
  <li>Respect strict de la norme de l’école 42</li>
</ul>

<hr>

<h2>Compilation et exécution</h2>

<pre>
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
</pre>

<hr>

<h2>Remarque</h2>

<p>
Ce projet met l’accent sur la rigueur et la précision.
Une mauvaise synchronisation entraîne des comportements incorrects
ou non déterministes.
</p>

</body>
</html>
