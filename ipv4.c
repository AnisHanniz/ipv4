#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_IPV4 255

// Structure pour stocker une adresse IPv4
struct ipv4_address {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
};

// Fonction pour générer une adresse IPv4 aléatoire
struct ipv4_address generate_random_ipv4() {
    struct ipv4_address ip;
    ip.octet1 = rand() % (MAX_IPV4 + 1);
    ip.octet2 = rand() % (MAX_IPV4 + 1);
    ip.octet3 = rand() % (MAX_IPV4 + 1);
    ip.octet4 = rand() % (MAX_IPV4 + 1);
    return ip;
}

// Fonction pour afficher une adresse IPv4
void print_ipv4(struct ipv4_address ip) {
    printf("%d.%d.%d.%d", ip.octet1, ip.octet2, ip.octet3, ip.octet4);
}

// Fonction pour afficher les informations d'une adresse IPv4
void print_ipv4_info(struct ipv4_address ip, int cidr_prefix) {
    // Calcul du masque de sous-réseau
    int mask = 0xFFFFFFFF << (32 - cidr_prefix);

    // Calcul de l'adresse réseau
    struct ipv4_address network_address;
    network_address.octet1 = ip.octet1 & (mask >> 24);
    network_address.octet2 = ip.octet2 & (mask >> 16 & MAX_IPV4);
    network_address.octet3 = ip.octet3 & (mask >> 8 & MAX_IPV4);
    network_address.octet4 = ip.octet4 & (mask & MAX_IPV4);

    // Calcul de l'adresse de diffusion
    struct ipv4_address broadcast_address;
    broadcast_address.octet1 = network_address.octet1 | (~mask >> 24);
    broadcast_address.octet2 = network_address.octet2 | (~mask >> 16 & MAX_IPV4);
    broadcast_address.octet3 = network_address.octet3 | (~mask >> 8 & MAX_IPV4);
    broadcast_address.octet4 = network_address.octet4 | (~mask & MAX_IPV4);

    // Adresse hôte
    struct ipv4_address host_address;
    host_address.octet1 = ip.octet1 & ~(mask >> 24);
    host_address.octet2 = ip.octet2 & ~(mask >> 16 & MAX_IPV4);
    host_address.octet3 = ip.octet3 & ~(mask >> 8 & MAX_IPV4);
    host_address.octet4 = ip.octet4 & ~(mask & MAX_IPV4);

    // Affichage des informations
    printf("\nAdresse IPv4: ");
    print_ipv4(ip);
    printf("/%d\n", cidr_prefix);
    printf("Masque de sous-réseau: ");
    print_ipv4((struct ipv4_address){mask >> 24, (mask >> 16) & 0xFF, (mask >> 8) & 0xFF, mask & 0xFF});
    printf("\nAdresse réseau: ");
    print_ipv4(network_address);
    printf("\nAdresse hôte: ");
    print_ipv4(host_address);
    printf("\nPlage d'adresses IP adressable:\n");
    printf("Min: ");
    print_ipv4((struct ipv4_address){network_address.octet1, network_address.octet2, network_address.octet3, network_address.octet4 + 1});
    printf("\nMax: ");
    print_ipv4((struct ipv4_address){broadcast_address.octet1 - 1, broadcast_address.octet2, broadcast_address.octet3, broadcast_address.octet4 - 1});
    printf("\nAdresse de diffusion: ");
    print_ipv4(broadcast_address);
    printf("\n");
}

// Fonction principale
int main() {
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires avec le temps actuel

    int choice;
    printf("Menu:\n");
    printf("1 - Générer une adresse IPv4 aléatoire\n");
    printf("2 - Saisir une adresse IPv4 manuellement\n");
    printf("Choix : ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Générer une adresse IPv4 aléatoire
        struct ipv4_address random_ipv4 = generate_random_ipv4();
        int cidr_prefix = 24; // CIDR /24 pour le subnet prefix
        print_ipv4_info(random_ipv4, cidr_prefix);
    } else if (choice == 2) {
        // Saisir une adresse IPv4 manuellement
        char ip_str[16]; // pour stocker l'adresse IPv4 sous forme de chaîne de caractères
        int cidr_prefix;

        printf("Entrez une adresse IPv4 (format : xxx.xxx.xxx.xxx) : ");
        scanf("%s", ip_str);
        printf("Entrez le préfixe de sous-réseau (CIDR) : ");
        scanf("%d", &cidr_prefix);

        // Analyser l'adresse IPv4 saisie
        struct ipv4_address manual_ipv4;
        sscanf(ip_str, "%d.%d.%d.%d", &manual_ipv4.octet1, &manual_ipv4.octet2, &manual_ipv4.octet3, &manual_ipv4.octet4);

        print_ipv4_info(manual_ipv4, cidr_prefix);
    } else {
        printf("Choix invalide.\n");
    }

    return 0;
}
