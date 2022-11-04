# -*- coding: cp949 -*-

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

def login():
    file = open('./userid.txt', 'r')
    
    login_id = browser.find_element(By.NAME, 'userid')
    login_id.send_keys(file.readline().strip('\n'))

    login_pw = browser.find_element(By.NAME, 'password')
    login_pw.send_keys(file.readline().strip('\n'))

    file.close()

    login_pw.send_keys(Keys.ENTER)

def enter_forum(num = '370454'):
    #browser.find_elements(By.CSS_SELECTOR('a')).click()
    pass



#driver = webdriver.Chrome('./chromedriver.exe')

options = webdriver.ChromeOptions()
options.add_experimental_option('excludeSwitches', ['enable-logging'])
browser = webdriver.Chrome(options = options)

url = 'https://everytime.kr/login'

browser.get(url) #접속할 url

login()

enter_forum()
