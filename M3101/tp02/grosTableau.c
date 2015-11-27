#define N 23170

static volatile char Image[N][N]; // image de N lignes et N colonnes

int main()
{
	int colonne;
	int ligne;

	// mise à zéro de l'image
	for (colonne=0; colonne<N; colonne++) // pour chaque colonne faire..
		for (ligne=0; ligne<N; ligne++)       // pour chaque ligne faire..
		{
			Image[ligne][colonne] = 0;
		}
	for (colonne=0; colonne<N; colonne++) // pour chaque colonne faire..
		for (ligne=0; ligne<N; ligne++)       // pour chaque ligne faire..
		{
			Image[ligne][colonne] = 0;
		}


	return 0;
}
