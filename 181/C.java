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
	long a, b;
	int n;
	long mod = 1000000000 + 7;
	long fact[] = new long[1111111];

	long power(long a, long b, long m) {
		if(b == 0)
			return 1l;
		long ret = power(a, b/2, m);
		ret = (ret*ret)%m;
		if(b %2 == 1)
			ret = (ret*a) % m;
		return ret;
	}
	long inv(long a) {
		return power(a, mod-2, mod);
	}

	boolean good(long n) {
		while(n > 0) {
			if(n % 10 == a || n % 10 == b)
				;
			else 
				return false;
			n /= 10;
		}
		return true;
	}
	void solve() {
		a = getLong(); b = getLong(); n = getInt();
		fact[0] = 1;
		for(int i = 1; i < 1011111; i++)
			fact[i] = (fact[i-1]*i)% mod;

		long ans = 0;

		for(int x = 0; x <= n; x++) {
			int y = n - x;
			if(good(x*a + y*b) == false)
				continue;
//			debug(x, y);
			long tmp = fact[n];
			tmp = tmp*inv(fact[x]);
			tmp = tmp%mod;
			tmp = tmp*inv(fact[y]);
			tmp = tmp%mod;
			ans+=tmp;
			ans = (ans%mod);
		}
		writeln(ans);
	}

	public static void main(String [] args) throws Exception
	{
		initShinChanNohara();
		new C().solve();
	}

//================================================================
	static BufferedReader br;
	static StringTokenizer strTok;

	static void initShinChanNohara() {
		br = new BufferedReader(new InputStreamReader(System.in));
		strTok = null;
	}

	static void initShinChanNohara(String file) {
		try {
			br = new BufferedReader(new FileReader(file));
			strTok = null;
		}
		catch(FileNotFoundException e) {
			writeln(e);
		}
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
	static void debug(Object ... ob) {
		System.out.println(Arrays.deepToString(ob));
	}
}

