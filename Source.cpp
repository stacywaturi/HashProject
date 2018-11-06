#define _CRT_SECURE_NO_WARNINGS 
#include <conio.h>
#include <openssl/sha.h>
#include "Hash.h"

int calc_sha256(const char* path, unsigned char hash[SHA256_DIGEST_LENGTH]);
void sha256_hash_string(unsigned char hash[SHA256_DIGEST_LENGTH], char outputBuffer[65]);

int main(int argc, char** argv[])
{
	/*std::string algorithm = "RS256";
	std::string string1 = "hello world";
	Hash hashObj;
	std::string hashed = "";


	if (algorithm == "RS256" || algorithm == "ES256") {
		hashed = hashObj.SHA256hash(string1).c_str();
		std::cout <<  "Hash value	:" << hashObj.SHA256hash(string1).c_str() << std::endl;
	}
	else if (algorithm == "RS384" || algorithm == "RS384") {
		hashed = hashObj.SHA384hash(string1).c_str();
		std::cout << "Hash value	:" << hashObj.SHA384hash(string1).c_str() << std::endl;
	}
	else if (algorithm == "RS512" || algorithm == "ES512") {
		hashed = hashObj.SHA512hash(string1).c_str();
		std::cout << "Hash value	:"  << hashObj.SHA512hash(string1).c_str() << std::endl;
	}
	else
		std::cout << "NOT A VALID ALGORITHM" << std::endl;*/





	//-------------------------------------------------------------------


	unsigned char calc_hash[65];

	calc_sha256("file.txt", calc_hash);

	system("pause");
	return 0;

}


int calc_sha256(const char* path, unsigned char hash[SHA256_DIGEST_LENGTH])
{
	FILE* file = fopen(path, "rb");
	if (!file) return -1;

	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	const int bufSize = 32768;
	char* buffer = (char*)malloc(bufSize);
	int bytesRead = 0;
	if (!buffer) return -1;
	while ((bytesRead = fread(buffer, 1, bufSize, file)))
	{
		SHA256_Update(&sha256, buffer, bytesRead);
	}
	SHA256_Final(hash, &sha256);

	
	fclose(file);
	free(buffer);
	char outputBuffer[65];
	sha256_hash_string(hash, outputBuffer);
	return 0;
}

void sha256_hash_string(unsigned char hash[SHA256_DIGEST_LENGTH], char outputBuffer[65])
{
	int i = 0;

	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
	{
		sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
	}

	outputBuffer[64] = 0;
}


