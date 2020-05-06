#include "com_typoface_jwoff2_WOFF2.h"

#include <string>

#include <woff2/encode.h>
#include <woff2/decode.h>
#include <fstream>
#include <iterator>

using std::string;

JNIEXPORT jbyteArray JNICALL Java_com_typoface_jwoff2_WOFF2_convertTTF2WOFF2Byte(
		JNIEnv *env, jclass cls, jbyteArray bytearray) {
		
	uint8_t* input_data =  (uint8_t*) (env->GetByteArrayElements(bytearray, 0));
	int chars_len = env->GetArrayLength(bytearray);

	size_t output_size = woff2::MaxWOFF2CompressedSize(input_data, chars_len);
	string output(output_size, 0);
	uint8_t* output_data = (uint8_t*)(&output[0]);
	woff2::WOFF2Params params;
	if (!woff2::ConvertTTFToWOFF2(input_data, chars_len, output_data,
			&output_size, params)) {
		fprintf(stderr, "Compression failed.\n");
		env->ReleaseByteArrayElements(bytearray, (jbyte*)( input_data), 0);
		
		exit(1);
	}
	output.resize(output_size);

	jbyteArray arr = env->NewByteArray(output_size);
	env->SetByteArrayRegion(arr, 0, output_size, (jbyte*)(output_data));
	
	env->ReleaseByteArrayElements(bytearray, (jbyte*)( input_data), 0);
	
	return arr;
}

JNIEXPORT jboolean JNICALL Java_com_typoface_jwoff2_WOFF2_convertTTF2WOFF2(
		JNIEnv *env, jclass cls, jstring jfilename, jstring joutfilename) {

	const char *in_str = NULL;
	const char *ou_str = NULL;

	in_str = env->GetStringUTFChars(jfilename, NULL);
	ou_str = env->GetStringUTFChars(joutfilename, NULL);

	string filename(in_str);
	string outfilename(ou_str);
	env->ReleaseStringUTFChars(jfilename,in_str);
	env->ReleaseStringUTFChars(joutfilename,ou_str);
	
	fprintf(stdout, "Processing %s => %s\n", filename.c_str(),
			outfilename.c_str());
	std::ifstream ifs(filename.c_str(), std::ios::binary);
	string input = string(
	    std::istreambuf_iterator<char>(ifs.rdbuf()),
	    std::istreambuf_iterator<char>());
	const uint8_t* input_data = reinterpret_cast<const uint8_t*>(input.data());
	size_t output_size = woff2::MaxWOFF2CompressedSize(input_data,
			input.size());
	string output(output_size, 0);
	uint8_t* output_data = reinterpret_cast<uint8_t*>(&output[0]);

	woff2::WOFF2Params params;
	if (!woff2::ConvertTTFToWOFF2(input_data, input.size(), output_data,
			&output_size, params)) {
		fprintf(stderr, "Compression failed.\n");
		return false;
	}
	output.resize(output_size);

	std::ofstream ofs(outfilename.c_str(), std::ios::binary);
	std::copy(output.begin(), output.end(), std::ostream_iterator<char>(ofs));
	return true;

}

/*
 * Class:     com_typoface_jwoff2_WOFF2
 * Method:    convertWOFF2ToTTF
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_typoface_jwoff2_WOFF2_convertWOFF2ToTTF(
		JNIEnv *env, jclass cls, jstring jfilename, jstring joutfilename) {

	const char *in_str = NULL;
	const char *ou_str = NULL;

	in_str = env->GetStringUTFChars(jfilename, NULL);
	ou_str = env->GetStringUTFChars(joutfilename, NULL);

	string filename(in_str);
	string outfilename(ou_str);
	fprintf(stdout, "Processing %s => %s\n", filename.c_str(),
			outfilename.c_str());

	std::ifstream ifs(filename.c_str(), std::ios::binary);
	string input = string(
	    std::istreambuf_iterator<char>(ifs.rdbuf()),
	    std::istreambuf_iterator<char>());

	const uint8_t* raw_input = reinterpret_cast<const uint8_t*>(input.data());
	string output(
			std::min(woff2::ComputeWOFF2FinalSize(raw_input, input.size()),
					woff2::kDefaultMaxSize), 0);
	woff2::WOFF2StringOut out(&output);

	const bool ok = woff2::ConvertWOFF2ToTTF(raw_input, input.size(), &out);

	if (ok) {
		  std::ofstream ofs(outfilename.c_str(), std::ios::binary);
		  std::copy(output.begin(), output.begin() + out.Size(), std::ostream_iterator<char>(ofs));
	}
	return ok ? true : false;

}
