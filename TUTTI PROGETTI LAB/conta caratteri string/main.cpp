#include <iostream>
 #include <string>
 using namespace std;


int WordOccurrenceCount( std::string const & str, std::string const & word )
{
       int count(0);
       std::string::size_type word_pos( 0 );
       while ( word_pos!=std::string::npos )
       {
               word_pos = str.find(word, word_pos );
               if ( word_pos != std::string::npos )
               {
                       ++count;

         // start next search after this word
                       word_pos += word.length();
               }
       }

       return count;
}


int main()
{

   string sting1="theeee peeeearl is in theeee riveeeer";
   string word1="e";
   cout<<word1<<" occurs "<<WordOccurrenceCount(sting1,word1)<<" times in ["<<sting1 <<"] \n\n";

   return 0;
}
