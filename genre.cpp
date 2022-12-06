#include "genre.h"

//buildMovie: read from input file and create corresponding movie type
Movie* Genre::buildMovie(ifstream& stream)
{
    Movie* newMovie = nullptr;
    char movieType;

    //set movie type
    stream >> movieType;

    //if fail to read movie type
    if (stream.fail()) 
    {
        stream.clear();
        stream.ignore(99, '\n');
        return nullptr;
    }

    //build specific type movie based on the input file
    switch (movieType) 
    {
    case MovieType::ComedyType:
        newMovie = buildMovieComedy(stream);
        break;
    case MovieType::ClassicType:
        newMovie = buildMovieClassic(stream);
        break;
    case MovieType::DramaType:
        newMovie = buildMovieDrama(stream);
        break;
    default:
        error(movieType, stream);
        break;
    }
    return newMovie;
}

//buildMovieComedy: create a comedy type movie from the input file
Movie* Genre::buildMovieComedy (ifstream& stream)
{
    Movie* comedy = new Comedy();
    if (comedy->setData(stream))
        return comedy;
    delete comedy;
    return nullptr;
}

//buildMovieDrama: create a drama type movie from the input file
Movie* Genre::buildMovieDrama(ifstream& stream) 
{
    Movie* drama = new Drama();
    if (drama->setData(stream))
        return drama;
    delete drama;
    return nullptr;
}

//buildMovieClassic: create a classic type movie from the input file
Movie* Genre::buildMovieClassic(ifstream& stream) 
{
    Movie* classic = new Classic();
    if (classic->setData(stream))
        return classic;
    delete classic;
    return nullptr;
}

//error: check and show error message to the user if the movie type is not included
void Genre::error(const char& mType, ifstream& stream) 
{
    string fullInfo;
    getline(stream, fullInfo);
    cerr << "Media, type \'" << mType << "\' is not recognized:"
        << '\n' << "  " << mType << fullInfo << endl;
}