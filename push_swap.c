/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:37:03 by nbarbosa          #+#    #+#             */
/*   Updated: 2025/12/10 14:39:13 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // Nécessaire pour printf

/*
** DEFINITION DE print_stack
** Tu peux la copier/coller dans ton fichier de test
*/
void print_stack(t_stack *s, char *name)
{
    printf("--- Stack %s ---\n", name);
    if (!s)
    {
        printf("EMPTY\n");
        printf("----------------\n");
        return;
    }
    while (s)
    {
        // Assure-toi que ta structure a bien un champ 'content' et 'index'
        printf("Content: %d, Index: %d\n", s->value, s->index);
        s = s->next;
    }
    printf("----------------\n");
}

/*
** PROTOTYPES DES FONCTIONS PRINCIPALES DE TON PROJET
*/
t_stack *ft_create_stack(char **av);
void ft_assign_index(t_stack *a);
void radix_sort(t_stack **a, t_stack **b);
int ft_lstsize(t_stack *a);
void ft_free_stack(t_stack **a); // Ajouté pour la bonne gestion mémoire

/*
** MAIN DU PROJET POUR LE DIAGNOSTIC
*/
int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    int size;

    // 1. Gestion des arguments
    if (argc < 2) 
        return (0);

    // 2. CRÉATION DE LA PILE (Lecture de argv)
    a = ft_create_stack(argv); 
    
    // 3. Vérification des Erreurs de Création
    if (!a)
    {
        printf("Error\n"); 
        return (1); // Retourne une erreur (gestion des doublons/format)
    }
    
    size = ft_lstsize(a);
    printf("--- Diagnostic du Tri Radix (N=%d) ---\n", size);
    
    // 4. Indexation (Cruciale pour le Radix)
    ft_assign_index(a);
    printf("\nÉTAPE 1: Piles après Indexation (Index 0 à %d):\n", size - 1);
    print_stack(a, "A");

    // 5. Exécution du Tri
    printf("\nÉTAPE 2: Début du Radix Sort...\n");
    radix_sort(&a, &b);
    printf("ÉTAPE 2: Fin du Radix Sort.\n");

    // 6. Vérification du Résultat Final
    printf("\nÉTAPE 3: RÉSULTAT FINAL:\n");
    print_stack(a, "A (Doit être triée)");
    print_stack(b, "B (Doit être vide)");

    // 7. Libérer la mémoire à la fin du programme
    ft_free_stack(&a); 
    
    return (0);
}