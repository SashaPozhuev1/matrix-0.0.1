#include <iostream>
#include <sstream>

using namespace std;

int MATRIX( int mass[ 3 ][ 3 ] ) {
	string stroka;
	bool prav = true;

	for ( int i = 0; i < 3; i++ ) {
		getline( cin, stroka );
		istringstream  stream( stroka );
		
		for ( int j = 0; j < 3; j++ ) {
			if ( !( stream >> mass[ i ][ j ] ) ) {
				prav = false;
				break;
			}
		}

	}
  
	return prav;
}

void Slozh( int mass1[ 3 ][ 3 ], int mass2[ 3 ][ 3 ] ){
	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			 cout << mass1[ i ][ j ] + mass2[ i ][ j ] << "	";
		}
		cout << '\n';
	}
}

void Vichit( int mass1[ 3 ][ 3 ], int mass2[ 3 ][ 3 ] ) {
  for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			cout << mass1[ i ][ j ] - mass2[ i ][ j ] << "	";
		}
		cout << '\n';
	}
}

void Ymnozh( int mass1[ 3 ][ 3 ], int mass2[ 3 ][ 3 ] ) {
	int mass3[ 3 ][ 3 ];
	
	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			int element = 0;
			
			for ( int k = 0; k < 3; k++ ) {
				element += mass1[ i ][ k ] * mass2[ k ][ j ];
			}
			
			mass3[ i ][ j ] = element;
			
			cout << mass3[ i ][ j ] << "	";
		}
		
		cout << '\n';
	}
}

void er() {
	cout << "An error has occured while reading input data" << '\n';
}

int main()
{
	int matrix1[ 3 ][ 3 ];
	int matrix2[ 3 ][ 3 ];
	string symbol;

	if ( MATRIX( matrix1 ) ) {

		getline( cin, symbol );

		if ( MATRIX( matrix2 ) ) {
			if ( symbol == "+" ) {
				Slozh( matrix1, matrix2 );
			}
			else if ( symbol == "-" ) {
				Vichit( matrix1, matrix2 );
			}
			else if ( symbol == "*" ) {
				Ymnozh( matrix1, matrix2 );
			}
			else {
				er();
			}
		}
		else {
			er();
		}
	}
	else {
		er();
	}
	
	cin.get();
    return 0;
}
