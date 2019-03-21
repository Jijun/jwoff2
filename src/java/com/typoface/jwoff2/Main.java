package com.typoface.jwoff2;
/**
 * a test class
 * @author ranger
 *
 */
public class Main {
	
	public static void main(String[] args) {
		if (args == null || args.length < 3) {
			System.out.println(
					"help: \n java -Djava.library.path=<link to libjwoff2> -jar libjwoff2.jar inputfilename outputfilename [woff2ttf|ttf2woff2] "
			);
			return;
		}

		String inputFileName = args[0];
		String outputFileName = args[1];
		String type = args[2];

		if ("woff2ttf".equalsIgnoreCase(type)) {
			WOFF2.convertWOFF2ToTTF(inputFileName, outputFileName);
		} else if ("ttf2woff2".equalsIgnoreCase(type)) {
			WOFF2.convertTTF2WOFF2(inputFileName, outputFileName);
		} else {
			System.out.println("no type defined");
		}

	}

}