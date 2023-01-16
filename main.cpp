/*
██████╗░███████╗██████╗░░█████╗░██╗░░░░░██╗░░░░░███████╗████████╗
██╔══██╗██╔════╝██╔══██╗██╔══██╗██║░░░░░██║░░░░░██╔════╝╚══██╔══╝
██████╔╝█████╗░░██████╦╝███████║██║░░░░░██║░░░░░█████╗░░░░░██║░░░
██╔══██╗██╔══╝░░██╔══██╗██╔══██║██║░░░░░██║░░░░░██╔══╝░░░░░██║░░░
██║░░██║███████╗██████╦╝██║░░██║███████╗███████╗███████╗░░░██║░░░
╚═╝░░╚═╝╚══════╝╚═════╝░╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝░░░╚═╝░░░
    Hash toolkit
 * @author Emtyfay
 * @description Fast hash toolkit
 */
#include <iostream>
#include <cxxopts.hpp>
#include <cryptopp/sha.h>
#include <cryptopp/md5.h>
#include <cryptopp/blake2.h>
#include <cryptopp/md2.h>
#include <cryptopp/md4.h>
#include <utils.h>
#include <string>
#include <fstream>


#define CXXOPTS_USE_UNICODE true
using namespace std;
using namespace CryptoPP;
string tmp;
const string logo = "\n"
                    "██████╗░███████╗██████╗░░█████╗░██╗░░░░░██╗░░░░░███████╗████████╗\n"
                    "██╔══██╗██╔════╝██╔══██╗██╔══██╗██║░░░░░██║░░░░░██╔════╝╚══██╔══╝\n"
                    "██████╔╝█████╗░░██████╦╝███████║██║░░░░░██║░░░░░█████╗░░░░░██║░░░\n"
                    "██╔══██╗██╔══╝░░██╔══██╗██╔══██║██║░░░░░██║░░░░░██╔══╝░░░░░██║░░░\n"
                    "██║░░██║███████╗██████╦╝██║░░██║███████╗███████╗███████╗░░░██║░░░\n"
                    "╚═╝░░╚═╝╚══════╝╚═════╝░╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝░░░╚═╝░░░\n"
                    "\nHash Toolkit";

int main(int argc, char **argv) {
    cout << logo << endl;
    cxxopts::Options options("ReballetHash", "Fast hash decoder");
    options.add_options()
            ("q,queries", "Path to file of queries", cxxopts::value<string>()->default_value(""))
            ("a,algorithm", "Hashing algorithm", cxxopts::value<string>()->default_value("md5"))
            ("H,hash", "hash to decode", cxxopts::value<string>()->default_value(""))
            ("t,trim", "Trim the line for hashing", cxxopts::value<bool>())
            ("h,help", "Help")
            ("L,linehash", "Hash line by line", cxxopts::value<bool>())
            ("o,outfile", "File to output", cxxopts::value<string>()->default_value("reballethash.output"))
            ;

    auto result = options.parse(argc, argv);
    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(0);
    }
    if(result["linehash"].as<bool>()) {
        ifstream infile;
        ofstream outfile;
        infile.open(result["queries"].as<string>());
        if(!infile.is_open()) {
            cout << "Unable to open input file" << endl;
            return 1;
        }
        outfile.open(result["outfile"].as<string>());
        if(!outfile.is_open()) {
            cout << "Unable to open output file" << endl;
            return 1;
        }
        cout << "Input file: " << result["queries"].as<string>() << endl;
        cout << "Output file: " << result["outfile"].as<string>() << endl;
        string algorithm = result["algorithm"].as<string>();
        transform(algorithm.begin(), algorithm.end(), algorithm.begin(), ::tolower);


        string line;
        while (getline(infile, line)) {
            if(result["trim"].as<bool>())trim(line);
            if(line.empty()) continue;
            string hash;

            if (algorithm == "md5") {
                hash = hashIt<MD5>(line);
            } else if (algorithm == "md4") {
                hash = hashIt<MD4>(line);
            } else if (algorithm == "md2") {
                hash = hashIt<MD2>(line);
            } else if(algorithm == "sha1") {
                hash = hashIt<SHA1>(line);
            } else if(algorithm == "sha256") {
                hash = hashIt<SHA256>(line);
            } else if(algorithm == "sha224") {
                hash = hashIt<SHA224>(line);
            } else if(algorithm == "sha384") {
                hash = hashIt<SHA384>(line);
            } else if(algorithm == "sha512") {
                hash = hashIt<SHA512>(line);
            } else if(algorithm == "blake2b") {
                hash = hashIt<BLAKE2b>(line);
            } else if(algorithm == "blake2s") {
                hash = hashIt<BLAKE2s>(line);
            } else {
                cout << "Incorrect or unsupported algorithm!" << endl;
                return 1;
            }
            outfile << line << " - "<< hash << "\n";

        }




    } else {
        if(result["queries"].as<string>().empty()) {
            string algorithm = result["algorithm"].as<string>();
            transform(algorithm.begin(), algorithm.end(), algorithm.begin(), ::tolower);
            string line = result["queries"].as<string>();

            string hash;

            if (algorithm == "md5") {
                hash = hashIt<MD5>(line);
            } else if (algorithm == "md4") {
                hash = hashIt<MD4>(line);
            } else if (algorithm == "md2") {
                hash = hashIt<MD2>(line);
            } else if(algorithm == "sha1") {
                hash = hashIt<SHA1>(line);
            } else if(algorithm == "sha256") {
                hash = hashIt<SHA256>(line);
            } else if(algorithm == "sha224") {
                hash = hashIt<SHA224>(line);
            } else if(algorithm == "sha384") {
                hash = hashIt<SHA384>(line);
            } else if(algorithm == "sha512") {
                hash = hashIt<SHA512>(line);
            } else if(algorithm == "blake2b") {
                hash = hashIt<BLAKE2b>(line);
            } else if(algorithm == "blake2s") {
                hash = hashIt<BLAKE2s>(line);
            } else {
                cout << "Incorrect or unsupported algorithm!" << endl;
                return 1;
            }
            cout << "hash of " + line + " is " + hash << endl;
        } else {
            ifstream file;
            file.open(result["queries"].as<string>());
            if (!file.is_open()) {
                cout << "Unable to open file" << endl;
                return 1;
            }
            string algorithm = result["algorithm"].as<string>();
            transform(algorithm.begin(), algorithm.end(), algorithm.begin(), ::tolower);

            string hashParam = result["hash"].as<string>();
            transform(hashParam.begin(), hashParam.end(), hashParam.begin(), ::tolower);
            string line;
            while (getline(file, line)) {
                if(result["trim"].as<bool>())trim(line);
                if(line.empty()) continue;
                string hash;

                if (algorithm == "md5") {
                    hash = hashIt<MD5>(line);
                } else if (algorithm == "md4") {
                    hash = hashIt<MD4>(line);
                } else if (algorithm == "md2") {
                    hash = hashIt<MD2>(line);
                } else if(algorithm == "sha1") {
                    hash = hashIt<SHA1>(line);
                } else if(algorithm == "sha256") {
                    hash = hashIt<SHA256>(line);
                } else if(algorithm == "sha224") {
                    hash = hashIt<SHA224>(line);
                } else if(algorithm == "sha384") {
                    hash = hashIt<SHA384>(line);
                } else if(algorithm == "sha512") {
                    hash = hashIt<SHA512>(line);
                } else if(algorithm == "blake2b") {
                    hash = hashIt<BLAKE2b>(line);
                } else if(algorithm == "blake2s") {
                    hash = hashIt<BLAKE2s>(line);
                } else {
                    cout << "Incorrect or unsupported algorithm!" << endl;
                    return 1;
                }
                if(hash == hashParam) {
                    cout << "[FOUND] Hash phrase is " << line << endl;
                    tmp = line;
                }
            }
        }




    }



    return 0;


}



