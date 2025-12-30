<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8">
  <title>Philosophers</title>
  <style>
    body {
      font-family: Arial, Helvetica, sans-serif;
      background-color: #0d1117;
      color: #c9d1d9;
      line-height: 1.6;
      padding: 20px;
    }
    h1, h2, h3 {
      color: #58a6ff;
    }
    hr {
      border: 0;
      height: 1px;
      background: #30363d;
      margin: 30px 0;
    }
    ul {
      margin-left: 20px;
    }
    code {
      background-color: #161b22;
      color: #79c0ff;
      padding: 2px 6px;
      border-radius: 4px;
    }
    pre {
      background-color: #161b22;
      padding: 15px;
      border-radius: 6px;
      overflow-x: auto;
      color: #c9d1d9;
    }
    strong {
      color: #f0f6fc;
    }
  </style>
</head>
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
