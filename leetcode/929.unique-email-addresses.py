class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        ans = set()
        for e in emails:
            ans.add(self.convert(e))
            
        return len(ans)
        
        
    def convert(self, email):
        local, at, domain = email.partition('@')
        
        if '+' in local:
            local = local[:local.index('+')]
            
        return local.replace('.', '') + at + domain