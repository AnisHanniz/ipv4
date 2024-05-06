# Programme IPv4 et IPv6

Ce programme en C permet le calcul et l'affichage de différentes informations telles que le masque de sous-réseau, l'adresse réseau, l'adresse hôte, la plage d'adresses IP adressable et l'adresse de diffusion à partir d'une adresse ip v4 ou v6 entrées manuellement ou générées aléatoirement.

## Compilation et exécution

Pour compiler le programme IPv4, utilisez la commande suivante :

```bash
gcc ipv4.c -o ipv4
```

Pour exécuter le programme IPv4, utilisez la commande suivante :

```bash
./ipv4
```

Pour compiler le programme IPv6, utilisez la commande suivante :

```bash
gcc ipv6.c -o ipv6
```

Pour exécuter le programme IPv6, utilisez la commande suivante :

```bash
./ipv6
```

## Utilisation

Le programme IPv4 affiche un menu où l'utilisateur peut choisir entre les options suivantes :

1. **Générer une adresse IPv4 aléatoire** : Le programme génère une adresse IPv4 aléatoire avec un préfixe de sous-réseau (CIDR) de 24 bits.
2. **Saisir une adresse IPv4 manuellement** : L'utilisateur entre une adresse IPv4 et le préfixe de sous-réseau (CIDR).

Le programme IPv4 affiche ensuite les informations de l'adresse IPv4 saisie ou générée, telles que le masque de sous-réseau, l'adresse réseau, l'adresse hôte, la plage d'adresses IP adressable et l'adresse de diffusion.

Le programme IPv6 génère une adresse IPv6 aléatoire avec un préfixe de sous-réseau (CIDR) de 64 bits et affiche les mêmes informations que le programme IPv4.

## Exemple

Voici un exemple d'exécution du programme IPv4 :

```
Menu:
1 - Générer une adresse IPv4 aléatoire
2 - Saisir une adresse IPv4 manuellement
Choix : 1

Adresse IPv4: 192.168.1.125/24
Masque de sous-réseau: 255.255.255.0
Adresse réseau: 192.168.1.0
Adresse hôte: 0.0.0.125
Plage d'adresses IP adressable:
Min: 192.168.1.1
Max: 192.168.1.254
Adresse de diffusion: 192.168.1.255
```

Voici un exemple d'exécution du programme IPv6 :

```
Menu:
1 - Générer une adresse IPv6 aléatoire
2 - Quitter
Choix : 1

Adresse IPv6: d25a:cbb1:8eea:d0f:66f6:1511:704b:2b9d/64
Masque de sous-réseau: ffff:ffff:ffff:ffff:0:0:0:0
Adresse réseau: d25a:cbb1:8eea:d0f:0:0:0:0
Adresse hôte: 0:0:0:0:66f6:1511:704b:2b9d
Plage d'adresses IP adressable:
Min: d25a:cbb1:8eea:d0f:0:0:0:1
Max: d259:cbb1:8eea:d0f:ffff:ffff:ffff:fffe
Adresse de diffusion: d25a:cbb1:8eea:d0f:ffff:ffff:ffff:ffff
```

## Auteur

Ce programme a été développé par Anis Hanniz.
