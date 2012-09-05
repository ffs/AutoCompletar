#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int main(int argc, char *argv[]) {
	FILE *dicionario = fopen("dicionario", "r");
	if (!dicionario) {
		printf("Erro ao abrir o dicionario de palavras!\n");
		return EXIT_FAILURE;
	}

	Trie *trie = trie_new();

	while (!feof(dicionario)) {
		char *palavra = malloc(64 * sizeof(char));
		fscanf(dicionario, "%s", palavra);

		trie_insert(trie, palavra, palavra);
	}

	return EXIT_SUCCESS;
}
