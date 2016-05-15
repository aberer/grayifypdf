#include "fillpoles.hxx"

#include <string>
#include <fstream>
#include <ostream>
#include <sstream>


std::ostream&
insertDelimiterIfNecessary(std::ostream& out, bool &hasBeenWrittenTo)
{
    if (hasBeenWrittenTo)
        out << ",";
    else
        hasBeenWrittenTo = true;

    return out;
}


// Exceptions                           logic_error
//
std::ostream&
fillGaps(unsigned int start,
         unsigned int end,
         const std::string& label,
         const std::string& complementLabel,
         const PoleSet& poles,
         std::ostream& out)
{
    auto wroteFirstElem = false;
    PoleSet::const_iterator poleIt = poles.begin();

    if (end < start)
    {
        throw std::logic_error("incorrect range");
    }
    else if (poleIt != poles.end() &&
             (*poleIt < start || *poleIt > end))
    {
        std::stringstream ss;
        ss << "pole " << *poleIt << " is out of range " << start <<
            " - " << end << std::endl;
        throw std::logic_error(ss.str());
    }
    else
    {
        PoleSet::value_type cur = start;

        while (cur <= end)
        {
            if (poleIt != poles.end())
            {
                if (cur == *poleIt)
                {
                    insertDelimiterIfNecessary(out, wroteFirstElem)
                        << complementLabel << cur;
                    ++cur;
                    ++poleIt;
                }
                else if (cur + 1 == *poleIt)
                {
                    insertDelimiterIfNecessary(out, wroteFirstElem)
                        << label << cur;
                    wroteFirstElem = true;
                    cur += 1;
                }
                else
                {
                    insertDelimiterIfNecessary(out, wroteFirstElem)
                        << label << cur << "-" << (*poleIt - 1);
                    wroteFirstElem = true;
                    cur = *poleIt;
                }
            }
            else
            {
                if (cur == end)
                {
                    insertDelimiterIfNecessary(out, wroteFirstElem)
                        << label << cur;
                }
                else
                {
                    insertDelimiterIfNecessary(out, wroteFirstElem)
                        << label <<  cur << "-" << end;
                }

                cur = end + 1;
            }
        }
    }
}
