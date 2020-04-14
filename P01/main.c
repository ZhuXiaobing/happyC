#include <stdio.h>
#include "include/movies.h"
#include <tgmath.h>
void showMovies(NodeItem * movies);

int main() {
    Movies movies;
    InitMovieList(movies);
    NodeItem item;
    printf("enter the title\n");
    scanf("%s", item.node.title);
    printf("enter the rating\n");
    scanf("%lf", &item.node.rating);
    if (MovieListIsFull(movies) == false) {
        AddItemToMovieList(item, &movies);
    }
    if (MovieListIsEmpty(movies) == false) {
        ShowMovieList(movies, showMovies);
    }
    FreeMovieList(movies);
}

void showMovies(Movies movies) {
    printf("TITLE:%s, RATING:%f", movies->node.title, movies->node.rating);
}
