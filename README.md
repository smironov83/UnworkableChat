#  н̶е̶Работающий чат
UnworkableChat - Это итоговый проект по первому модулю курса «Разработчик на C++» от oнлайн-школы SkillFactory.

В UnworkableChat реализовано:
- Регистрация новых пользователей
- Авторизация пользователей с использованием связки логин/пароль
- Отображение информации о статусе пользователей
- Создание сообщений и выбор пользователей для отправки
- Отображение истории сообщений

> Чтобы пользователь не заскучал, пока его друзья оффлайн, реализован пользователь чат-бот. 
> Его ответы попадают всегда в точку. 
> Он лучше всяких исскуственных интелектов ChatGPT

#  Классы, реализованные в UnworkableChat

| Class         | Including                                                                                                                                          |
| ------        | ------                                                                                                                                             |
| Users         | `string login`, `string password`, `string name`, `bool online`, `vector<string> history`                                                          |
| Message       | `string timeStamp`, `string from`, `string to`, `string text`                                                                                      |
| CommandModule | `vector<Users> users`, `Users* user`, `Message* message`, `vector<string> chatBotAnswers`, `size_t currentUser`, `bool worksChat`, `bool worksUser`|
| bad_range     |                                                                                                                                                    |

#  Не одно отправленное сообщение не потеряется!
