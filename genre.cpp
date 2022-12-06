/* @file genre.cpp
 * @brief The following code gives the implementations of the genre class
 * @author Anthony Vu
 * @date 12/05/2022
 */

#include "genre.h"

/* buildMovie reads from the input file and creates a corresponding movie type
 */
Movie* Genre::buildMovie(ifstream& stream) {
    Movie* newMovie = nullptr;
    char movieType;

    stream >> movieType;

    if (stream.fail()) {
        stream.clear();
        stream.ignore(99, '\n');
        return nullptr;
    }

    switch (movieType) {
    case MovieType::ComedyType:
        newMovie = buildComedy(stream);
        break;
    case MovieType::ClassicType:
        newMovie = buildClassic(stream);
        break;
    case MovieType::DramaType:
        newMovie = buildDrama(stream);
        break;
    default:
        error(movieType, stream);
        break;
    }
    return newMovie;
}

/* buildComedy creates a comedy type movie
 */
Movie* Genre::buildComedy (ifstream& stream) {
    Movie* comedy = new Comedy();
    if (comedy->setData(stream)) {
        return comedy;
    }
    delete comedy;
    return nullptr;
}

/* buildDrama creates a drama type movie
 */
Movie* Genre::buildDrama(ifstream& stream) {
    Movie* drama = new Drama();
    if (drama->setData(stream)) {
        return drama;
    }
    delete drama;
    return nullptr;
}

/* buildClassic creates a classic type movie
 */
Movie* Genre::buildClassic(ifstream& stream) {
    Movie* classic = new Classic();
    if (classic->setData(stream)) {
        return classic;
    }
    delete classic;
    return nullptr;
}

/* error checks if the movie type is not included 
 */
void Genre::error(const char& mType, ifstream& stream) {
    string fullInfo;
    getline(stream, fullInfo);
    cerr << "Media, type \'" << mType << "\' is not recognized:"
        << '\n' << "  " << mType << fullInfo << endl;
}