# Programme IPv4

Ce programme en C permet de générer une adresse IPv4 aléatoire ou de saisir une adresse IPv4 manuellement, puis calcule et affiche différentes informations telles que le masque de sous-réseau, l'adresse réseau, l'adresse hôte, la plage d'adresses IP adressable et l'adresse de diffusion.

## Compilation et exécution

Pour compiler le programme, utilisez la commande suivante :

```bash
gcc ipv4.c -o ipv4
```

Pour exécuter le programme, utilisez la commande suivante :

```bash
./ipv4
```

## Utilisation

Le programme affiche un menu où l'utilisateur peut choisir entre les options suivantes :

1. **Générer une adresse IPv4 aléatoire** : Le programme génère une adresse IPv4 aléatoire avec un préfixe de sous-réseau (CIDR) de 24 bits.
2. **Saisir une adresse IPv4 manuellement** : L'utilisateur entre une adresse IPv4 et le préfixe de sous-réseau (CIDR).

Le programme affiche ensuite les informations de l'adresse IPv4 saisie ou générée, telles que le masque de sous-réseau, l'adresse réseau, l'adresse hôte, la plage d'adresses IP adressable et l'adresse de diffusion.

## Exemple

Voici un exemple d'exécution du programme :

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

## Auteur

Ce programme a été développé par Anis Hanniz.
