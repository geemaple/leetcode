class Logger:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
    
    @staticmethod
    def log(content, color='', end='\n'):
        ENDC = '\033[0m'
        print(f"{color}{content}{ENDC}", end=end)

    @staticmethod
    def test_all():
        Logger.log("HEADER", Logger.HEADER)
        Logger.log("OKBLUE", Logger.OKBLUE)

        Logger.log("OKCYAN", Logger.OKCYAN)
        Logger.log("OKGREEN", Logger.OKGREEN)
        Logger.log("WARNING", Logger.WARNING)
        Logger.log("FAIL", Logger.FAIL)
        Logger.log("BOLD", Logger.BOLD)
        Logger.log("UNDERLINE", Logger.UNDERLINE)

if __name__ == '__main__':
    Logger.test_all()