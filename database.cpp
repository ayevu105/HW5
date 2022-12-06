/* @file database.cpp
 * @brief The following code gives the implementations of the database class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "database.h"

//database constructor
Database::Database() {
    movies.insert(pair<MovieType, BST<InventoryDatabase>>(MovieType::ComedyType, comedies));
    movies.insert(pair<MovieType, BST<InventoryDatabase>>(MovieType::ClassicType, classics));
    movies.insert(pair<MovieType, BST<InventoryDatabase>>(MovieType::DramaType, dramas));
}

//destructor
Database::~Database(){}

/* insert inserts the media type into the data base
 */
bool Database::insert(InventoryDatabase* media) {
    if(media->getMediaType() == MediaType::DVDMovie) {
        return insertMovie(media);
    }
    return false;
}

/* insertMovie is the helper function to movie
 */
bool Database::insertMovie(InventoryDatabase* movie)
{
    MovieType type = dynamic_cast<Movie*>(movie)->getMovieType();
    if (type == MovieType::ComedyType) {
        return movies.at(MovieType::ComedyType).insert(movie);
    } else if (type == MovieType::ClassicType) {
        return movies.at(MovieType::ClassicType).insert(movie);
    } else if (type == MovieType::DramaType) {
        return movies.at(MovieType::DramaType).insert(movie);
    } else {
        return false;
    }
}

/* retrieve returns the target media
 */
bool Database::retrieve(const InventoryDatabase& target, InventoryDatabase*& retriever) {
    if (target.getMediaType() == MediaType::DVDMovie) {
        return retrieveMovie(target, retriever);
    }

    return false;
}

/* retrieveMovie is the helper function to retrieve
 */
bool Database::retrieveMovie(const InventoryDatabase& target, InventoryDatabase*& retriever) {
    MovieType type = dynamic_cast<const Movie&>(target).getMovieType();
    if (type == MovieType::ComedyType) {
        return movies.at(MovieType::ComedyType).retrieve(target, retriever);
    } else if (type == MovieType::ClassicType) {
        return movies.at(MovieType::ClassicType).retrieve(target, retriever);
    } else if (type == MovieType::DramaType) {
        return movies.at(MovieType::DramaType).retrieve(target, retriever);
    } else {
        return false;
    }
}

/* remove removes the media type from the data base
 */
bool Database::remove(const InventoryDatabase& target) {
    if (target.getMediaType() == MediaType::DVDMovie) {
        return removeMovie(target);
    }
    return false;
}

/* removeMovie is the helper function to remove
 */
bool Database::removeMovie(const InventoryDatabase& target) {
    if (dynamic_cast<const Movie&>(target).getMovieType() == MovieType::ComedyType) {
        return movies.at(MovieType::ComedyType).remove(target);
    } else if (dynamic_cast<const Movie&>(target).getMovieType() == MovieType::ClassicType) {
        return movies.at(MovieType::ClassicType).remove(target);
    } else if (dynamic_cast<const Movie&>(target).getMovieType()== MovieType::DramaType) {
        return movies.at(MovieType::DramaType).remove(target);
    } else {
        return false;
    }
}

/* display displays all the elements in the database
 */
void Database::display() const {
    movies.at(MovieType::ComedyType).display();
    movies.at(MovieType::DramaType).display();
    movies.at(MovieType::ClassicType).display();
}

/* getTotalMedia retrieves the number of media in the database
 */
int Database::getTotalMedia() const {
    return getTotalMovie();
}

/* getTotalMovie is the helper function for getTotalMedia
 */
int Database::getTotalMovie() const {
    int t = movies.at(MovieType::ComedyType).getTotalNode() + movies.at(MovieType::DramaType).getTotalNode() + movies.at(MovieType::ClassicType).getTotalNode();
    return t;
}