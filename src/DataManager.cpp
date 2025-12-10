#include "../include/DataManager.h"

// Define the static member
#ifdef _WIN32
    const string DataManager::DATA_PATH = "data\\";
#else
    const string DataManager::DATA_PATH = "data/";
#endif

// Save functions
template < typename t >
void DataManager::saveToFile( const string & fileName , map <int,t*> & Table )
{    
    string filePath = DATA_PATH + fileName ;

    ofstream file ( filePath ) ;

    if ( !file.is_open() ) return ;

    file << t::ID_START << " " << Table.size() << "\n" ;

    for ( auto obj : Table )
    {
        if ( obj ) 
            file << obj->toCSV() << "\n" ;
    }

    file.close() ;
}


void DataManager::saveData()
{
    filesystem::create_directories( DATA_PATH ) ;

    // saveToFile< example > ( "example.dat" , map <int,example * > exampleTable) ;
}


// Load functions
template < typename t >
void DataManager::LoadFromFile( const string & fileName )
{
    string filePath = DATA_PATH + fileName ;

    ifstream file ( filePath ) ;

    if ( !file.is_open() ) throw runtime_error( "Fail to load" ) ; 
    
    int cnt ;
    file >> t::ID_START >> cnt ;
    file.ignore() ;

    while ( cnt -- )
    {
        string entity ;
        getline( file , entity ) ;
        
        if ( !entity.empty() )
            t::fromCSV( entity ) ;
    }

    file.close() ;
}

void DataManager::loadInitialData()
{
    
}

void DataManager::loadData()
{
    filesystem::create_directories( DATA_PATH ) ;

    // LoadFromFile < example > ( "example.dat" ) ;

}
