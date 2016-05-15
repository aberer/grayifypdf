#ifndef FILLPOLES_H
#define FILLPOLES_H

#include <set>
#include <iosfwd>

typedef std::set<unsigned int> PoleSet;


// _____________________________________________________________________________
//
// Exceptions                           logic_error
std::ostream&                           fillGaps(
    unsigned int start,
    unsigned int end,
    const std::string& label,
    const std::string& complementLabel,
    const PoleSet& poles,
    std::ostream& out);


#endif /* FILLPOLES_H */
