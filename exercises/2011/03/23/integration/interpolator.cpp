// vim: set ts=2 sts=2 sw=2 et:

#include <cstdlib>

#include <vector>
#include <sstream>
#include <iomanip>
#include <iostream>

#include "interpolator/Polynomial.h"

using namespace std;

int main(int argc, char *argv[]) 
{
  double                          from;
  double                          to;
  unsigned int                    nSteps;
  vector< pair<double, double> >  points;
  string                          line;
  unsigned int                    i;
  double                          x;

	if (argc < 4) {
    cerr << "Usage: " << argv[0] << ' ' << "<from> <to> <nsteps>" << endl;
    return -1;
  }

  from    = atof(argv[1]);
  to      = atof(argv[2]);
  nSteps  = atoi(argv[3]);

  cerr << "Ok, reading points from stdin:" << endl;
  while (getline(cin, line)) {
    istringstream ss(line);
    double x, y;
    ss >> x;
    ss >> y;
    points.push_back( *new pair<double, double>(x, y) ); 
  }

  interpolator::Polynomial intpl(points);

  cout << setprecision(16);
  
  double deltaX = (to - from)/(double)nSteps;
  for(i = 0; i <= nSteps; i++ ) {
    x = from + i*deltaX;
    cout << x << ' ' << intpl.interpolate(x) << endl;
  }

  return 0;
}

