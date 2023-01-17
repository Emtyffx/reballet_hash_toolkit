#include <string>
#include <cstdio>
#include <cryptopp/hex.h>
#include <algorithm>
#include <cctype>
#include <locale>
using namespace std;
using namespace CryptoPP;

template <typename Algo>
string hashIt(const string &query) {
    CryptoPP::byte digest[Algo::DIGESTSIZE];

    Algo hashFunc;
    hashFunc.CalculateDigest(digest, (const CryptoPP::byte*)query.c_str(), query.length());

    string output;
    HexEncoder encoder;
    encoder.Attach(new StringSink(output));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    transform(output.begin(), output.end(), output.begin(), ::tolower);
    return output;

}


// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
[[maybe_unused]] static inline void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}

// trim from start (copying)
[[maybe_unused]] static inline std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
[[maybe_unused]] static inline std::string rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
[[maybe_unused]] static inline std::string trim_copy(std::string s) {
    trim(s);
    return s;
}