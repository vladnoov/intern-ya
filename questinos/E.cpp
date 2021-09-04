»меетс€ n пользователей, каждому из них соответствует список email - ов(всего m email - ов).Ќапример:
user1->xxx@ya.ru, foo@gmail.com, lol@mail.ru
user2->foo@gmail.com, ups@pisem.net
user3->xyz@pisem.net, vasya@pupkin.com
user4->ups@pisem.net, aaa@bbb.ru
user5->xyz@pisem.net

foo@gmail.com : user1
xxx@ya.ru : user1
lol@mail.ru : user1


—читаетс€, что если у двух пользователей есть общий email, значит это одни и тот же пользователь.
“ребуетс€ построить и реализовать алгоритм, выполн€ющий сли€ние пользователей.Ќа выходе должен быть список пользователей с их email - ами(такой же как на входе).¬ качестве имени объединенного пользовател€ можно брать любое из исходных имен.—писок email - ов пользовател€ должен содержать только уникальные email - ы.ѕараметры n и m произвольные, длина конкретного списка email - ов никак не ограничена.
¬ указанном примере ответ на задачу будет следующий :
user1->xxx@ya.ru, foo@gmail.com, lol@mail.ru, ups@pisem.net, aaa@bbb.ru
user3->xyz@pisem.net, vasya@pupkin.com


