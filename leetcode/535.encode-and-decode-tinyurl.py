import string
import random
class Codec:

    def __init__(self):
        self.url2code = {}
        self.code2url = {}
    
    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        letters = string.ascii_letters + "0123456789"
        
        while longUrl not in self.url2code:
            code = ''.join(random.choice(letters) for i in range(6))
            if code not in self.code2url:
                self.url2code[longUrl] = code
                self.code2url[code] = longUrl
                
        return 'http://tinyurl.com/' + self.url2code[longUrl]
            
    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.code2url[shortUrl[-6:]]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))