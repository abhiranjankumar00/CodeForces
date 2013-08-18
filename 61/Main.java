//-----------
//----lost---
//-----------

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
/*
- 128 to 127

2) short occupies 2 bytes and allows you to store numbers from  - 32768 to 32767

3) int occupies 4 bytes and allows you to store numbers from  - 2147483648 to 2147483647

4) long occupies 8 bytes and allows you to store numbers from  - 9223372036854775808 to 9223372036854775807
*/
public class Main
{
	public static void main(String [] args) throws Exception
	{
		BufferedReader br   = new BufferedReader (new InputStreamReader(System.in));
		BigInteger posByte  = new BigInteger("127");
		BigInteger negByte  = new BigInteger("-128");
		BigInteger posShort = new BigInteger("32767");
		BigInteger negShort = new BigInteger("-32768");
		BigInteger  posInt  = new BigInteger("2147483647");
		BigInteger negInt   = new BigInteger("-2147483648");
		BigInteger posLong  = new BigInteger("9223372036854775807");
		BigInteger negLong	= new BigInteger("-9223372036854775808");
		
		BigInteger num = new BigInteger(br.readLine());
		
		if(num.compareTo(negByte) >= 0 && num.compareTo(posByte) <= 0 )
			System.out.println("byte");
		else if(num.compareTo(negShort) >= 0 && num.compareTo(posShort) <= 0)
			System.out.println("short");
		else if(num.compareTo(negInt) >= 0 && num.compareTo(posInt) <= 0)
			System.out.println("int");
		else if(num.compareTo(negLong) >= 0 && num.compareTo(posLong) <= 0)
			System.out.println("long");
		else
			System.out.println("BigInteger");

	}
}
