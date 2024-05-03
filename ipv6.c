#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define IPV6_SEGMENT_COUNT 8
#define IPV6_SEGMENT_BITS 16
#define IPV6_SEGMENT_MAX 0xFFFF

// Structure pour stocker une adresse IPv6
struct ipv6_address {
    uint16_t segments[IPV6_SEGMENT_COUNT];
};

// Fonction pour générer une adresse IPv6 aléatoire
struct ipv6_address generate_random_ipv6() {
    struct ipv6_address ip;
    for (int i = 0; i < IPV6_SEGMENT_COUNT; ++i) {
        ip.segments[i] = rand() % (IPV6_SEGMENT_MAX + 1);
    }
    return ip;
}

// Fonction pour afficher une adresse IPv6
void print_ipv6(struct ipv6_address ip) {
    for (int i = 0; i < IPV6_SEGMENT_COUNT; ++i) {
        printf("%x", ip.segments[i]);
        if (i != IPV6_SEGMENT_COUNT - 1) {
            printf(":");
        }
    }
}

// Fonction pour afficher les informations d'une adresse IPv6
void print_ipv6_info(struct ipv6_address ip, int cidr_prefix) {
    // Calcul du masque de sous-réseau
    uint16_t mask_segments[IPV6_SEGMENT_COUNT] = {0};
    int full_segments = cidr_prefix / IPV6_SEGMENT_BITS;
    int partial_bits = cidr_prefix % IPV6_SEGMENT_BITS;

    for (int i = 0; i < full_segments; ++i) {
        mask_segments[i] = IPV6_SEGMENT_MAX;
    }

    if (partial_bits > 0) {
        mask_segments[full_segments] = (uint16_t)(IPV6_SEGMENT_MAX << (IPV6_SEGMENT_BITS - partial_bits));
    }

    // Calcul de l'adresse réseau
    struct ipv6_address network_address;
    for (int i = 0; i < IPV6_SEGMENT_COUNT; ++i) {
        network_address.segments[i] = ip.segments[i] & mask_segments[i];
    }

    // Calcul de l'adresse de diffusion
    struct ipv6_address broadcast_address;
for (int i = 0; i < IPV6_SEGMENT_COUNT; ++i) {
    broadcast_address.segments[i] = network_address.segments[i] | ~mask_segments[i];
}

    // Adresse hôte
    struct ipv6_address host_address;
    for (int i = 0; i < IPV6_SEGMENT_COUNT; ++i) {
        host_address.segments[i] = ip.segments[i] & ~mask_segments[i];
    }

    // Affichage des informations
    printf("\nAdresse IPv6: ");
    print_ipv6(ip);
    printf("/%d\n", cidr_prefix);
    printf("Masque de sous-réseau: ");
    print_ipv6((struct ipv6_address){.segments = {mask_segments[0], mask_segments[1], mask_segments[2], mask_segments[3],
                                                  mask_segments[4], mask_segments[5], mask_segments[6], mask_segments[7]}});

    printf("\nAdresse réseau: ");
    print_ipv6(network_address);
    printf("\nAdresse hôte: ");
    print_ipv6(host_address);
    printf("\nPlage d'adresses IP adressable:\n");
    printf("Min: ");
    print_ipv6((struct ipv6_address){.segments = {network_address.segments[0], network_address.segments[1],
                                                  network_address.segments[2], network_address.segments[3],
                                                  network_address.segments[4], network_address.segments[5],
                                                  network_address.segments[6], network_address.segments[7] + 1}});
    printf("\nMax: ");
    print_ipv6((struct ipv6_address){.segments = {broadcast_address.segments[0] - 1, broadcast_address.segments[1],
                                                  broadcast_address.segments[2], broadcast_address.segments[3],
                                                  broadcast_address.segments[4], broadcast_address.segments[5],
                                                  broadcast_address.segments[6], broadcast_address.segments[7] - 1}});
    printf("\nAdresse de diffusion: ");
    print_ipv6(broadcast_address);
    printf("\n");
}

// Fonction principale
int main() {
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires avec le temps actuel

    int choice;
    printf("Menu:\n");
    printf("1 - Générer une adresse IPv6 aléatoire\n");
    printf("2 - Quitter\n");
    printf("Choix : ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Générer une adresse IPv6 aléatoire
        struct ipv6_address random_ipv6 = generate_random_ipv6();
        int cidr_prefix = 64; // CIDR /64 pour le subnet prefix
        print_ipv6_info(random_ipv6, cidr_prefix);
    } else if (choice == 2) {
        // Quitter
        printf("Bye!\n");
    } else {
        printf("Choix invalide.\n");
    }

    return 0;
}
