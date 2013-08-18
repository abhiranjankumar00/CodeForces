//-----------
//----lost---
//-----------

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class d
{
	public static boolean pr[];
	public static int sz;
	public static  int len;
	public static  BigInteger prime [];

	public static void PreProcess()
	{
		sz = 100000;
		len = 0;
		prime = new BigInteger[sz/10];

		pr = new boolean[sz];

		for(int i = 0; i< sz; i++)	pr[i] = true;
		pr[0] = pr[1] = false;

		for(int i = 0; i* i <= sz; i++)
		{
			if(pr[i])
			{
				for(int j = i+i; j< sz; j+= i)
					pr[j] = false;
			}
		}

		for(int i = 0; i< sz; i++)
			if(pr[i])
				prime[len++] = new BigInteger(new Integer(i).toString());

		//System.out.println(len);

//		for(int i = 0; i< len; i++)
//			System.out.println(prime[i]);

	}

	public static void main(String [] args) throws Exception
	{
		PreProcess();
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));

//		String st = new Integer(2).toString();
//		BigInteger bi = new BigInteger(st);

//		System.out.println(bi);

		int n = Integer.parseInt(br.readLine());

		BigInteger ans[] = new BigInteger[n+1];

		int idx = 0;

		for(int i = 1; i <= n; i++)
			ans[i] = BigInteger.ONE;
			//ans[i] = prime[idx++];

		for(int i = 1; i<=n; i++)
		{
			for(int j = i+1; j<=n; j++)
			{
				ans[i] = ans[i].multiply(prime[idx]);
				ans[j] = ans[j].multiply(prime[idx++]);
			}
		}
		
		int maxLen = 0;
		
		for(int i = 1; i <=n; i++)
		{
			maxLen = Math.max(maxLen, ans[i].toString().length());
			//System.out.println(ans[i]);
		}

		if(maxLen <= 100)
			for(int i = 1; i<=n; i++)
			System.out.println(ans[i]);
			else
				System.out.println(-1);

		//System.out.println("\n"+ maxLen);

	}
}
