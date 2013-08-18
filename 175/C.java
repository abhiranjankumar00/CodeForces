//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class C
{
	public static void main(String [] args) throws Exception
	{
		initShinChanNohara();
		int N = getInt();

		Integer arr[] = new Integer[N];

		for(int i = 0; i < N; i++)
			arr[i] = getInt();

		Arrays.sort(arr);
		/*
		for(int i = 0; i < N; i++)
			write(arr[i], "");
		writeln("");
		*/

		long ans = 0;
		for(int i = 0; i < N; i++) {
			ans += abs(arr[i] - (i+1));
		}
		writeln(ans);

	}
	static long abs(long a) {
		return a >= 0 ? a : -a;
	}

//================================================================
	static BufferedReader br;
	static StringTokenizer strTok;

	static void initShinChanNohara() {
		br = new BufferedReader(new InputStreamReader(System.in));
		strTok = null;
	}

	static String getLine() {
		try {
			String st = br.readLine();
			return st;
		}
		catch(IOException e) {
			return null;
		}

	}

	static String getToken() {
		while(strTok == null || strTok.hasMoreTokens() == false) {
			String st = getLine();
			if(st == null)
				return null;
			strTok = new StringTokenizer(st);
		}
		return strTok.nextToken();
	}

	static int getInt() {
		return Integer.parseInt(getToken()); 
	}
	static double getDouble() {
		return Double.parseDouble(getToken());
	}
	static long getLong() {
		return Long.parseLong(getToken());
	}
	
	static void write(Object ... ob) {
		for(int i = 0; i < ob.length; i++) {
			if(i > 0)
				System.out.print(" ");
			System.out.print(ob[i]);
		}
	}
	static void writeln(Object ... ob) {
		write(ob);
		System.out.println();
	}
}


