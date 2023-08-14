import hashlib
import uuid

class User():
    __password = None

    def __init__(self):
        self.id = str(uuid.uuid4())

    @property
    def password(self):
        return self.__password

    @password.setter
    def password(self, pwd):
        if pwd is None or type(pwd) is not str:
            self.__password = None
        else:
            self.__password = hashlib.md5(pwd.encode()).hexdigest().lower()

    def is_valid_password(self, pwd):
        if pwd is None or type(pwd) is not str:
            return False
        if self.__password is None:
            return False
        return hashlib.md5(pwd.encode()).hexdigest().upper() == self.__password

if __name__ == '__main__':
    print("Test User")

    # Create two user instances
    user_1 = User()
    user_2 = User()

    # Check if user_1 has an id
    if user_1.id is None:
        print("New User should have an id")

    # Check if user ids are unique
    if user_1.id == user_2.id:
        print("User.id should be unique")

    u_pwd = "myPassword"
    # Set and check if password is hashed
    user_1.password = u_pwd
    if user_1.password == u_pwd:
        print("User.password should be hashed")

    # Check if user_2 password is None by default
    if user_2.password is not None:
        print("User.password should be None by default")

    # Set password to None and check if it remains None
    user_2.password = None
    if user_2.password is not None:
        print("User.password should be None if set to None")

    # Set password to an integer and check if it remains None
    user_2.password = 89
    if user_2.password is not None:
        print("User.password should be None if set to an integer")

    # Check if is_valid_password returns True for correct password
    if not user_1.is_valid_password(u_pwd):
        print("is_valid_password should return True if it's the right password")

    # Check if is_valid_password returns False for incorrect password
    if user_1.is_valid_password("Fakepwd"):
        print("is_valid_password should return False if it's not the right password")

    # Check if is_valid_password returns False when compared with None
    if user_1.is_valid_password(None):
        print("is_valid_password should return False if compared with None")

    # Check if is_valid_password returns False when compared with an integer
    if user_1.is_valid_password(89):
        print("is_valid_password should return False if compared with an integer")

    # Check if is_valid_password returns False for a password "No pwd"
    if user_2.is_valid_password("No pwd"):
        print("is_valid_password should return False if compared with 'No pwd'")

