# UMBC Cipher
## 1. Description
Your assignment is to implement a system that can be used to encrypt or decrypt three different ciphers. 

### Cipher 1: Caesar Cipher<br>
It is a simple substitution cipher. It is a type of substitution cipher in which each letter in the plaintext
(we will read it in as a file) is replaced by a letter some fixed number of positions down the alphabet. For example, if we shifted 3, ‘a’ would be a
‘d’. Our cipher must allow for the user to shift any legal integer number of places (always to the right). So, if we shifted an ‘e’ 100 places to the right,
it would be 100 % 26.

### Cipher 2: Vigenère Cipher<br>
The second cipher is a version of the Caesar cipher. It is a method of encrypting alphabetic text by using a series of
interwoven Caesar ciphers based on the letters of a keyword. Rather than using an integer to indicate the shift, we will use a
single word. For additional details: [click here](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)

### Cipher 3: Ong Cipher<br>
The last cipher is different than the first two. It works kind of like pig latin (and really isn’t a cipher). For the ong cipher,
for each character in the cipher, you are going to evaluate if it is a vowel or not. If it is a vowel, you will just ignore it. If it is a
consonant, you will add “ong” after every consonant. 

For example:<br>
UMBC = U-Mong-Bong-Cong<br> 
True Grit = Tong-rong-u-e Gong-rong-i-tong<br>
You should include the – between each letter in a word.

## 2. Background
Protecting data and even more importantly information is a concept that is common throughout headlines today. Articles ripped from
today’s headlines often read like this “Apple apps ranked as biggest security risk on the PC” or “Are people really your biggest
cyber security risk?”. So, what can we do as computer scientists to help reduce the risk of our data being compromised?

There are three main concepts that are at the heart of information security (Infosec). They are confidentiality, integrity, and availability (CIA for short).

Confidentiality: Information kept private and secure.<br>
Integrity: Data not modified, deleted, or added.<br>
Availability: Systems available to whom requires them.<br>
For this project, we are going to focus on confidentiality which is related to keeping our information private and secure. Many current system vulnerabilities
are related to not keeping our data confidential such as when Equifax had a data breach or Ashley Madison was hacked.

## 3. Overview
In this project, you will:
  *	Practice creating classes with inheritance 
  *	Working with pointers as they pertain to classes
  *	Using polymorphism
  *	Working with a larger number of classes

