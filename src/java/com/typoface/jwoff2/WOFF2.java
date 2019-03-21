package com.typoface.jwoff2;

/**
 * a java wrapper for google woff2
 * 
 * @author jijun
 *
 */
public class WOFF2 {
	static {
		System.loadLibrary("jwoff2");
	}

	public static native byte[] convertTTF2WOFF2Byte(byte[] inputByte);

	/**
	 * convert truetype font to woff2
	 * 
	 * @param intputFileName
	 * @param outputFileName
	 * @return
	 */
	public static native boolean convertTTF2WOFF2(String intputFileName, String outputFileName);

	/**
	 * convert woff2 to truetype font
	 * 
	 * @param inputFileName
	 * @param outputFileName
	 * @return
	 */
	public static native boolean convertWOFF2ToTTF(String inputFileName, String outputFileName);

}
