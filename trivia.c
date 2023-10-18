#include "pico/stdlib.h"
#include "trivia.h"

const trivia_t trivia_set_a[] = {
    {
  /* Pregunta #1. */
  level_medium, answer_c,
    
  /* ------------------------------------ */
  "¿Qué hacen los floriprofes en Navidad?  ",
    
  {
      /* ------------------------------------ */
      "A. Hacer dulces para sus dulces alumnos.",
      "B. Venir con un florigorro navideño.    ",
      "C. Cantar un villancico.                ",
      "D. Brindar todos en el patio.           ",
  },
    
  {
      /* ----- */
      "Dulces   ",
      "Gorros   ",
      "Cantar   ",
      "Brindar  ",
  },
  },
  {
  /* Pregunta #2. */
  level_hard, answer_a,
    
  /* ------------------------------------ */
  "¿Cuál es nuestro villancico oficial?  ",
    
  {
      /* ------------------------------------ */
      "A. La señora Ruperta.                   ",
      "B. Veinticinco de diciembre.            ",
      "C. Ya llegan las vacaciones.            ",
      "D. En el reino de la florinavidad.      ",
  },
    
  {
      /* ----- */
      "Ruperta  ",
      "Diciembre",
      "Ya llegan",
      "El reino ",
  },
  },
  {
  /* Pregunta #3. */
  level_medium, answer_d,
    
  /* ------------------------------------ */
  "¿Cómo se llama nuestra emisora de radio?",
    
  {
      /* ------------------------------------ */
      "A. FloriRadio                           ",
      "B. Radio Flori                          ",
      "C. FloriOnda                            ",
      "D. Onda Flori                           ",
  },
    
  {
      /* ----- */
      "FloriRd. ",
      "Rd. Flori",
      "FloriOnda",
      "On. Flori",
  },
  },
 {
  /* Pregunta #4. */
  level_medium, answer_c,
    
  /* ------------------------------------ */
  "¿A qué profesor le encantan los jamones?",
    
  {
      /* ------------------------------------ */
      "A. Yelo                             ",
      "B. Yolanda                               ",
      "C. Pedro Marín                          ",
      "D. Juan de Andrés                       ",
  },
    
  {
      /* ----- */
      "Yelo     ",
      "Yolanda  ",
      "Pd. Marín",
      "J. Andrés",
  },
  },


  {
  /* Pregunta #5. */
  level_easy, answer_a,
    
  /* ------------------------------------ */
  "¿Cómo se llama el trivial del flori?    ",
    
  {
      /* ------------------------------------ */
      "A. FloriQuiz                            ",
      "B. Trivial del Floridablanca            ",
      "C. FloriPreguntados                     ",
      "D. FloriQuest                           ",
  },
    
  {
      /* ----- */
      "FloriQuiz",
      "Trivial  ",
      "FloriPrg.",
      "FloriQst.",
  },
  },
  {
  /* Pregunta #6. */
  level_hard, answer_a,
    
  /* ------------------------------------ */
  "¿Qué profesor toca la batería?          ",
    
  {
      /* ------------------------------------ */
      "A. Paco Vico                            ",
      "B. Yelo                             ",
      "C. Juanjo                             ",
      "D. Luis Soler                           ",
  },
    
  {
      /* ----- */
      "Paco Vico",
      "Yelo     ",
      "Juanjo   ",
      "L. Soler ",
  },
  },
  {
  /* Pregunta #7. */
  level_medium, answer_d,
    
  /* ------------------------------------ */
  "¿Qué exprofe acompaña en el Floricamino?",
    
  {
      /* ------------------------------------ */
      "A. Juan                                 ",
      "B. José                                 ",
      "C. Jesús                                ",
      "D. Julio                                ",
  },
    
  {
      /* ----- */
      "Juan     ",
      "José     ",
      "Jesús    ",
      "Julio    ",
  },
  },
{
  /* Pregunta #8. */
  level_easy, answer_b,
    
  /* ------------------------------------ */
  "¿En qué curso (dig.) se realiza el ABP? ",
    
  {
      /* ------------------------------------ */
      "A. 1º y 3º de la ESO.                   ",
      "B. 1º y 2  de la ESO.               ",
      "C. 3º Y 4º de la ESO.                 ",
      "D. 1º y 2º de Bachillerato.             ",
  },
    
  {
      /* ----- */
      "1º/3º ESO",
      "1º/2º ESO",
      "3º/4º ESO",
      "1º/2º Ba.",
  },
  },
  {
  /* Pregunta #9. */
  level_easy, answer_c,
    
  /* ------------------------------------ */
  "¿Qué objeto usa el logo del Floricamino?",
    
  {
      /* ------------------------------------ */
      "A. Una cruz.                            ",
      "B. Una sardina.                         ",
      "C. Una concha.                          ",
      "D. Un limón.                            ",
  },
    
  {
      /* ----- */
      "Cruz     ",
      "Sardina  ",
      "Concha   ",
      "Limón    ",
  },
  },
{
  /* Pregunta #10. */
  level_easy, answer_c,
    
  /* ------------------------------------ */
  "¿En qué curso se realiza el Floricamino?",
    
  {
      /* ------------------------------------ */
      "A. 1º de ESO                            ",
      "B. 2º de ESO                            ",
      "C. 3º de ESO                            ",
      "D. 4º de ESO                            ",
  },
    
  {
      /* ----- */
      "1º ESO   ",
      "2º ESO   ",
      "3º ESO   ",
      "4º ESO   ",
  },
  },
  {
  /* Pregunta #11. */
  level_easy, answer_c,
    
  /* ------------------------------------ */
  "¿En qué planta está el aula 203?        ",
    
  {
      /* ------------------------------------ */
      "A. La planta baja.                      ",
      "B. La primera planta.                   ",
      "C. La segunda planta.                   ",
      "D. La tercera planta.                   ",
  },
    
  {
      /* ----- */
      "Baja     ",
      "Primera  ",
      "Segunda  ",
      "Tercera  ",
  },
  },
{
  /* Pregunta #12. */
  level_medium, answer_b,
    
  /* ------------------------------------ */
  "¿Si entro al IES donde está baño chicos?",
    
  {
      /* ------------------------------------ */
      "A. A la derecha.                        ",
      "B. A la izquierda.                      ",
      "C. En el sótano.                        ",
      "D. Solo hay baño de chicas.             ",
  },
    
  {
      /* ----- */
      "Derecha  ",
      "Izquierda",
      "Sótano   ",
      "No hay   ",
  },
  },
  {
  /* Pregunta #13. */
  level_easy, answer_c,
    
  /* ------------------------------------ */
  "En 2023, ¿cuál es nuestra directora?    ",
    
  {
      /* ------------------------------------ */
      "A. María del Carmen García              ",
      "B. Ana Juárez                           ",
      "C. María Encarnación Almecija           ",
      "D. Laura Sánchez                        ",
  },
    
  {
      /* ----- */
      "María    ",
      "Ana      ",
      "Mariem   ",
      "Laura    ",
  },
  },
  {
  /* Pregunta #14. */
  level_medium, answer_d,
    
  /* ------------------------------------ */
  "¿Qué gana en el torneo (liga) de fútbol?",
    
  {
      /* ------------------------------------ */
      "A. Vale de la cantina.                  ",
      "B. Una pelota.                          ",
      "C. 20€                              ",
      "D. Un florillavero.                     ",
  },
    
  {
      /* ----- */
      "Cantina  ",
      "Pelota   ",
      "20€      ",
      "Llavero  ",
  },
  },
  {
  /* Pregunta #15. */
  level_hard, answer_c,
    
  /* ------------------------------------ */
  "¿Cuánto cuesta una napolitana en 2023?  ",
    
  {
      /* ------------------------------------ */
      "A. 1,00 €                               ",
      "B. 2,00 €                               ",
      "C. 1,20 €                               ",
      "D. 1,50 €                               ",
  },
    
  {
      /* ----- */
      "1,00 €   ",
      "2,00 €   ",
      "1,20 €   ",
      "1,50 €   ",
  },
  },
 {
  /* Pregunta #16. */
  level_medium, answer_b,
    
  /* ------------------------------------ */
  "¿Qué proyecto V.I.D.A. tiene tecnología?",
    
  {
      /* ------------------------------------ */
      "A. Onda Flori.                          ",
      "B. FloriMakers.                         ",
      "C. Flori Tecnos.                        ",
      "D. Grupo Tecnológico.                   ",
  },
    
  {
      /* ----- */
      "On. Flori",
      "FloriMak.",
      "FloriTec.",
      "Gr. Tecno",
  },
  },
   {
  /* Pregunta #17. */
  level_hard, answer_b,
    
  /* ------------------------------------ */
  "¿Qué profe dice frecuentemente 'ea, ea'?",
    
  {
      /* ------------------------------------ */
      "A. Yésica                               ",
      "B. Ángel Luis                           ",
      "C. Antonio                              ",
      "D. Alicia                               ",
  },
    
  {
      /* ----- */
      "Dulces   ",
      "Gorros   ",
      "Cantar   ",
      "Brindar  ",
  },
  },
{
  /* Pregunta #18. */
  level_hard, answer_a,
    
  /* ------------------------------------ */
  "¿Cuánto es el cuadrado de queso en 2023?",
    
  {
      /* ------------------------------------ */
      "A. 1,50 €                               ",
      "B. 1,30 € si te perdonan los céntimos.  ",
      "C. 1,20 €                               ",
      "D. Gratis si haces un simpa.            ",
  },
    
  {
      /* ----- */
      "1,50 €   ",
      "1,30 €   ",
      "1,20 €   ",
      "Gratis   ",
  },
  },



  {
  /* Pregunta #19. */
  level_easy, answer_b,
    
  /* ------------------------------------ */
  "¿Cuántos años tiene nuestro instituto?  ",
    
  {
      /* ------------------------------------ */
      "A. Alrededor de 30 años.                ",
      "B. Alrededor de 50 años.                ",
      "C. Alrededor de 80 años.                ",
      "D. Más de 100 años.                     ",
  },
    
  {
      /* ----- */
      "30 años  ",
      "50 años  ",
      "80 años  ",
      "100 años ",
  },
  },
{
  /* Pregunta #20. */
  level_easy, answer_c,
    
  /* ------------------------------------ */
  "¿Cómo se llama el coro del instituto?   ",
    
  {
      /* ------------------------------------ */
      "A. FloriCantando.                       ",
      "B. Coro Flori.                          ",
      "C. FloriCoro.                           ",
      "D. La voz del flori.                    ",
  },
    
  {
      /* ----- */
      "FloriCnt.",
      "Co. Flori",
      "FloriCoro",
      "Voz Flori",
  },
  },


  {
  /* Pregunta #21. */
  level_hard, answer_c,
    
  /* ------------------------------------ */
  "¿Qué comida es propia del Floricamino?  ",
    
  {
      /* ------------------------------------ */
      "A. Cualquier tipo de pescado.           ",
      "B. Pulpo a la gallega.                  ",
      "C. Carne con patatas.                   ",
      "D. Platos de lentejas.                  ",
  },
    
  {
      /* ----- */
      "Pescado  ",
      "Pulpo    ",
      "Carne    ",
      "Lentejas ",
  },
  },
  {
  /* Pregunta #22. */
  level_easy, answer_b,
    
  /* ------------------------------------ */
  "¿Cuándo se cierra el baño?            ",
    
  {
      /* ------------------------------------ */
      "A. En el recreo.                    ",
      "B. En el cambio de clases.            ",
      "C. Las primeras tres horas.             ",
      "D. Las últimas tres horas.            ",
  },
    
  {
      /* ----- */
      "Recreo   ",
      "Cambio   ",
      "Primeras ",
      "Últimas  ",
  },
  },
  {
  /* Pregunta #23. */
  level_hard, answer_a,
    
  /* ------------------------------------ */
  "¿Qué pone bajo el logo del Floricamino? ",
    
  {
      /* ------------------------------------ */
      "A. 'Siempre hacia el oeste'             ",
      "B. 'Buen camino'                        ",
      "C. 'Siempre hacia el este'              ",
      "D. 'Siempre florijuntos'                ",
  },
    
  {
      /* ----- */
      "Oeste    ",
      "Camino   ",
      "Este     ",
      "Florijun.",
  },
  },
 {
  /* Pregunta #24. */
  level_medium, answer_d,
    
  /* ------------------------------------ */
  "¿Qué profesores crearon el FloriCamino? ",
    
  {
      /* ------------------------------------ */
      "A. Ángel Luis y Pedro Marín.            ",
      "B. Domingo y Amparo.                    ",
      "C. Vicente y Raquel.                    ",
      "D. Julio y Yelo.                        ",
  },
    
  {
      /* ----- */
      "Ang. Pdr.",
      "Dom. Amp.",
      "Vic. Raq.",
      "Jul. Yel.",
  },
  },


  {
  /* Pregunta #25. */
  level_medium, answer_a,
    
  /* ------------------------------------ */
  "¿Qué tema se trata en el A.B.P. de 1º?  ",
    
  {
      /* ------------------------------------ */
      "A. El Floricamino.                      ",
      "B. Las redes sociales.                  ",
      "C. La historia de España.               ",
      "D. El buen cuidado del medioambiente.   ",
  },
    
  {
      /* ----- */
      "Floricam.",
      "Redes S. ",
      "España   ",
      "Cuidado  ",
  },
  },
  {
  /* Pregunta #26. */
  level_easy, answer_a,
    
  /* ------------------------------------ */
  "¿Dónde está el dep. de Física y Química?",
    
  {
      /* ------------------------------------ */
      "A. En el laboratorio.               ",
      "B. En la cuarta planta.                 ",
      "C. Fuera al lado de la entrada.         ",
      "D. No hay.                            ",
  },
    
  {
      /* ----- */
      "Lab.     ",
      "4ª Planta",
      "Fuera.   ",
      "No hay.  ",
  },
  },
  {
  /* Pregunta #27. */
  level_hard, answer_b,
    
  /* ------------------------------------ */
  "¿Qué profesor dice a menudo 'Callais'?  ",
    
  {
      /* ------------------------------------ */
      "A. Encarnación                          ",
      "B. Rosario (Charo)                      ",
      "C. Ovidio                               ",
      "D. Jose Francisco Puche                 ",
  },
    
  {
      /* ----- */
      "Encarni  ",
      "Charo    ",
      "Ovidio   ",
      "Puche    ",
  },
  },
  {
  /* Pregunta #28. */
  level_medium, answer_a,
    
  /* ------------------------------------ */
  "¿Nombre proyecto para alumnos de 2º ESO?",
    
  {
      /* ------------------------------------ */
      "A. Proyecto V.I.D.A                     ",
      "B. GD Makers.                           ",
      "C. Grupos de Innovación.                ",
      "D. FloriVida.                           ",
  },
    
  {
      /* ----- */
      "V.I.D.A  ",
      "GD Makers",
      "Gr. Inno.",
      "FloriVida",
  },
  },
  {
  /* Pregunta #29. */
  level_medium, answer_d,
    
  /* ------------------------------------ */
  "¿Qué es tradición comer en Navidad?     ",
    
  {
      /* ------------------------------------ */
      "A. Churros con chocolate.               ",
      "B. Ferreros Rocher.                     ",
      "C. Un roscón de reyes.                  ",
      "D. Monas con chocolate.                 ",
  },
    
  {
      /* ----- */
      "Churros  ",
      "Ferreros ",
      "Roscón   ",
      "Monas    ",
  },
  },
  {
  /* Pregunta #30. */
  level_easy, answer_b,
    
  /* ------------------------------------ */
  "¿Cuál es el color temático del centro?  ",
    
  {
      /* ------------------------------------ */
      "A. Rojo                               ",
      "B. Azul                             ",
      "C. Púrpura                            ",
      "D. Ninguno en particular.               ",
  },
    
  {
      /* ----- */
      "Rojo     ",
      "Azul     ",
      "Púrpura  ",
      "Ninguno  ",
  },
  },


  {
  /* Pregunta #32. */
  level_easy, answer_a,
    
  /* ------------------------------------ */
  "¿Qué semana temática se repite siempre? ",
    
  {
      /* ------------------------------------ */
      "A. La semana de la ciencia.             ",
      "B. La semana de la historia.            ",
      "C. La semana de las Humanidades.        ",
      "D. La semana de las Artes.              ",
  },
    
  {
      /* ----- */
      "Ciencia. ",
      "Historia.",
      "Humanid. ",
      "Artes.   ",
  },
  },


  {
  /* Pregunta #34. */
  level_hard, answer_c,
    
  /* ------------------------------------ */
  "¿Dónde está la FloriCampana original?   ",
    
  {
      /* ------------------------------------ */
      "A. En uno de los patios.                ",
      "B. En el hall.                          ",
      "C. En el despacho de la directora.      ",
      "D. En secretaría.                       ",
  },
    
  {
      /* ----- */
      "Patios.  ",
      "Hall.    ",
      "Desp. Di.",
      "Secr.    ",
  },
  },


  {
  /* Pregunta #36. */
  level_hard, answer_b,
    
  /* ------------------------------------ */
  "¿Qué había en el Sal. Act. hasta 2022?  ",
    
  {
      /* ------------------------------------ */
      "A. Un cuadro del conde Floridablanca.   ",
      "B. Una tabla periódica.                 ",
      "C. Nada especial.                   ",
      "D. Un tablón de Anuncios.             ",
  },
    
  {
      /* ----- */
      "Cuadro.  ",
      "Tabla P. ",
      "Nada.    ",
      "Tab. Anu.",
  },
  },


  {
  /* Pregunta #38. */
  level_medium, answer_a,
    
  /* ------------------------------------ */
  "¿Qué se hace el día escol. de las mates?",
    
  {
      /* ------------------------------------ */
      "A. El campeonato de cálculo mental.     ",
      "B. La olimpiada de matemáticas.         ",
      "C. Un concurso de acertijos.            ",
      "D. Una carrera de sumas.                ",
  },
    
  {
      /* ----- */
      "C. Ment. ",
      "Olimpiada",
      "Acertijos",
      "Carrera. ",
  },
  },


  {
  /* Pregunta #40. */
  level_easy, answer_b,
    
  /* ------------------------------------ */
  "¿A qué hora toca la campana para entrar?",
    
  {
      /* ------------------------------------ */
      "A. 8.05                                 ",
      "B. 8.10                                 ",
      "C. 8.15                                 ",
      "D. No suena una campana, es una sirena. ",
  },
    
  {
      /* ----- */
      "8.05     ",
      "8.10     ",
      "8.15     ",
      "Sirena.  ",
  },
  },


  {
  /* Pregunta #42. */
  level_medium, answer_b,
    
  /* ------------------------------------ */
  "¿Dónde está el despacho del director@?  ",
    
  {
      /* ------------------------------------ */
      "A. Al fondo de la secretaría.           ",
      "B. Al fondo de jefatura.                ",
      "C. Detrás del salón de Actos.           ",
      "D. Al lado de la sala de profesores.    ",
  },
    
  {
      /* ----- */
      "Fondo Sec",
      "Fondo Jef",
      "Detr. S.A",
      "lado S.P ",
  },
  },


  {
  /* Pregunta #44. */
  level_hard, answer_b,
    
  /* ------------------------------------ */
  "¿Dónde se ubicaba originalmente el IES? ",
    
  {
      /* ------------------------------------ */
      "A. Dónde está ahora el IES Alfonso X.   ",
      "B. Dónde está ahora el IES Cascales.    ",
      "C. Dónde está ahora el IES Saavedra.    ",
      "D. Siempre ha estado en el mismo lugar. ",
  },
    
  {
      /* ----- */
      "Alfonso X",
      "Cascales ",
      "Saavedra ",
      "No cambia",
  },
  },


  {
  /* Pregunta #46. */
  level_medium, answer_d,
    
  /* ------------------------------------ */
  "Si estoy en la 201, ¿Dónde estoy?       ",
    
  {
      /* ------------------------------------ */
      "A. En el aula de artes plásticas.       ",
      "B. En el laboratorio de física.         ",
      "C. En el aula de música.                ",
      "D. En el taller de tecnología.          ",
  },
    
  {
      /* ----- */
      "Artes.   ",
      "Lab. Fis.",
      "Música.  ",
      "Taller.  ",
  },
  },


  {
  /* Pregunta #48. */
  level_easy, answer_a,
    
  /* ------------------------------------ */
  "¿Dónde está la estatua del Conde?       ",
    
  {
      /* ------------------------------------ */
      "A. En el patio delantero.               ",
      "B. En las pistas.                       ",
      "C. En el patio lateral.                 ",
      "D. En el patio trasero.                 ",
  },
    
  {
      /* ----- */
      "Delante. ",
      "Pistas.  ",
      "Lateral. ",
      "Trasero. ",
  },
  },




  {
  /* Pregunta #50. */
  level_easy, answer_b,
    
  /* ------------------------------------ */
  "¿Cuántos patios interiores hay?         ",
    
  {
      /* ------------------------------------ */
      "A. 1                                    ",
      "B. 2                                    ",
      "C. 3                                    ",
      "D. No hay patios interiores.            ",
  },
    
  {
      /* ----- */
      "1        ",
      "2        ",
      "3        ",
      "No hay   ",
  },
  },


  {
  /* Pregunta #52. */
  level_medium, answer_d,
    
  /* ------------------------------------ */
  "¿Qué se ofrece en bilingüe en 1º Bach?  ",
    
  {
      /* ------------------------------------ */
      "A. Historia.                            ",
      "B. Música.                              ",
      "C. Matemáticas.                         ",
      "D. Filosofía.                           ",
  },
    
  {
      /* ----- */
      "Historia ",
      "Música   ",
      "Mates    ",
      "Filosofía",
  },
  },


  {
  /* Pregunta #54. */
  level_easy, answer_a,
    
  /* ------------------------------------ */
  "¿Qué llevan los alumnos digitales?      ",
    
  {
      /* ------------------------------------ */
      "A. Un ipad.                             ",
      "B. Un chromebook.                       ",
      "C. Un portátil cualquiera.              ",
      "D. Un móvil.                            ",
  },
    
  {
      /* ----- */
      "Un ipad  ",
      "Chr.Book ",
      "Portátil ",
      "Un movil ",
  },
  },


  {
  /* Pregunta #56. */
  level_medium, answer_c,
    
  /* ------------------------------------ */
  "¿Cual es obligatoria en 1º BACH?        ",
    
  {
      /* ------------------------------------ */
      "A. Música.                              ",
      "B. Historia.                            ",
      "C. Educación Física.                    ",
      "D. Matemáticas.                         ",
  },
    
  {
      /* ----- */
      "Música   ",
      "Historia ",
      "E.F.     ",
      "Mates    ",
  },
  },


  {
  /* Pregunta #58. */
  level_hard, answer_d,
    
  /* ------------------------------------ */
  "¿Quién es jef@/fundador@ de OndaFlori?  ",
    
  {
      /* ------------------------------------ */
      "A. Ana Juarez.                          ",
      "B. Pedro Saura.                         ",
      "C. José Puche.                          ",
      "D. Encarnación Hernandez.               ",
  },
    
  {
      /* ----- */
      "Ana      ",
      "Pedro    ",
      "Puche    ",
      "Encarna  ",
  },
  },


  {
  /* Pregunta #60. */
  level_hard, answer_c,
    
  /* ------------------------------------ */
  "¿Dónde está el laboratorio de idiomas?  ",
    
  {
      /* ------------------------------------ */
      "A. Planta Baja.                         ",
      "B. Primera Planta.                      ",
      "C. Segunda Planta.                      ",
      "D. Tercera Planta.                      ",
  },
    
  {
      /* ----- */
      "Baja     ",
      "Primera  ",
      "Segunda  ",
      "Tercera  ",
  },
  },
};

const trivia_t trivia_set_b[] = {
    {
  /* Pregunta #1. */
  level_easy, answer_a,
    
  /* ------------------------------------ */
  "¿Quién es el dueño de Woody (Toy Story)?",
    
  {
      /* ------------------------------------ */
      "A. Andy.                                ",
      "B. Pitt.                                ",
      "C. Kid.                                 ",
      "D. Sid.                                 ",
  },
    
  {
      /* ----- */
      "Andy     ",
      "Pitt     ",
      "Kid      ",
      "Sid      ",
  },
  },
  {
  /* Pregunta #2. */
  level_easy, answer_c,
    
  /* ------------------------------------ */
  "¿Cual de las siguientes NO es de Disney?",
    
  {
      /* ------------------------------------ */
      "A. Aladdin.                             ",
      "B. El Rey León.                         ",
      "C. Los Minions.                         ",
      "D. La Bella Durmiente.                  ",
  },
    
  {
      /* ----- */
      "Aladdin  ",
      "ElReyLeón",
      "Minions  ",
      "Durmiente",
  },
  },
  {
  /* Pregunta #3. */
  level_easy, answer_b,
    
  /* ------------------------------------ */
  "¿En qué peli encontramos a Sebastián?   ",
    
  {
      /* ------------------------------------ */
      "A. Buscando a Nemo.                     ",
      "B. La Sirenita.                         ",
      "C. Delfi.                               ",
      "D. Pocahontas.                          ",
  },
    
  {
      /* ----- */
      "B. a Nemo",
      "Sirenita ",
      "Delfi    ",
      "Pocahonta",
  },
  },
  {
  /* Pregunta #4. */
  level_easy, answer_d,
    
  /* ------------------------------------ */
  "¿De qué color es la ropa de Peter Pan?  ",
    
  {
      /* ------------------------------------ */
      "A. Azul                                 ",
      "B. Roja                                 ",
      "C. Amarilla                             ",
      "D. Verde                                ",
  },
    
  {
      /* ----- */
      "Azul     ",
      "Roja     ",
      "Amarilla ",
      "Verde    ",
  },
  },
  {
  /* Pregunta #5. */
  level_easy, answer_a,
    
  /* ------------------------------------ */
  "¿Nombre del gato enemigo de los pitufos?",
    
  {
      /* ------------------------------------ */
      "A. Azraël.                              ",
      "B. Hércules.                            ",
      "C. Gargamel.                            ",
      "D. Félix.                               ",
  },
    
  {
      /* ----- */
      "Azraël   ",
      "Hércules ",
      "Gargamel ",
      "Félix    ",
  },
  },
  {
  /* Pregunta #6. */
  level_easy, answer_c,
    
  /* ------------------------------------ */
  "Un triángulo equilátero tiene…          ",
    
  {
      /* ------------------------------------ */
      "A. Dos lados iguales.                   ",
      "B. Un Ángulo Recto.                     ",
      "C. Tres lados iguales.                  ",
      "D. Tres lados diferentes.               ",
  },
    
  {
      /* ----- */
      "2 iguales",
      "Ang. Rect",
      "3 iguales",
      "3 difer. ",
  },
  },
  {
  /* Pregunta #7. */
  level_easy, answer_b,
    
  /* ------------------------------------ */
  "¿Cuántos lados tiene un hexágono?       ",
    
  {
      /* ------------------------------------ */
      "A. 8 lados.                             ",
      "B. 6 lados.                             ",
      "C. 5 lados.                             ",
      "D. 7 lados.                             ",
  },
    
  {
      /* ----- */
      "8        ",
      "6        ",
      "5        ",
      "7        ",
  },
  },
  {
  /* Pregunta #8. */
  level_easy, answer_d,
    
  /* ------------------------------------ */
  "¿Cuántos días tiene un año bisiesto?    ",
    
  {
      /* ------------------------------------ */
      "A. 370 días.                            ",
      "B. 365 días.                            ",
      "C. 360 días.                            ",
      "D. 366 días.                            ",
  },
    
  {
      /* ----- */
      "370      ",
      "365      ",
      "360      ",
      "366      ",
  },
  },
  {
  /* Pregunta #9. */
  level_easy, answer_a,
    
  /* ------------------------------------ */
  "¿Quién dicen que es el rey de la selva? ",
    
  {
      /* ------------------------------------ */
      "A. El león.                             ",
      "B. El búfalo.                           ",
      "C. El tigre.                            ",
      "D. El elefante.                         ",
  },
    
  {
      /* ----- */
      "León     ",
      "Búfalo   ",
      "Tigre    ",
      "Elefante ",
  },
  },
  {
  /* Pregunta #10. */
  level_easy, answer_c,
    
  /* ------------------------------------ */
  "¿Qué es una orquídea?                   ",
    
  {
      /* ------------------------------------ */
      "A. Un pez.                              ",
      "B. Un mamífero.                         ",
      "C. Una flor.                            ",
      "D. La mujer de una orca.                ",
  },
    
  {
      /* ----- */
      "Un pez   ",
      "Mamífero ",
      "Una Flor ",
      "Muj. Orca",
  },
  },
  {
  /* Pregunta #11. */
  level_easy, answer_b,
    
  /* ------------------------------------ */
  "¿En qué ciudad está el Louvre?          ",
    
  {
      /* ------------------------------------ */
      "A. Roma.                                ",
      "B. París.                               ",
      "C. Milán.                               ",
      "D. Madrid.                              ",
  },
    
  {
      /* ----- */
      "Roma     ",
      "París    ",
      "Milán    ",
      "Madrid   ",
  },
  },
  {
  /* Pregunta #12. */
  level_easy, answer_d,
    
  /* ------------------------------------ */
  "Mozart era un genio del mundo de…       ",
    
  {
      /* ------------------------------------ */
      "A. La televisión.                       ",
      "B. La literatura.                       ",
      "C. El deporte.                          ",
      "D. La música.                           ",
  },
    
  {
      /* ----- */
      "TV       ",
      "Literat. ",
      "Deporte  ",
      "Música   ",
  },
  },
  {
  /* Pregunta #13. */
  level_easy, answer_a,
    
  /* ------------------------------------ */
  "¿Escritura utilizada por gente ciega?   ",
    
  {
      /* ------------------------------------ */
      "A. Braille.                             ",
      "B. Jeroglífico.                         ",
      "C. Morse.                               ",
      "D. Ideograma.                           ",
  },
    
  {
      /* ----- */
      "Braille  ",
      "Jerogl.  ",
      "Morse    ",
      "Ideograma",
  },
  },
  {
  /* Pregunta #14. */
  level_easy, answer_c,
    
  /* ------------------------------------ */
  "Termina el refrán: En abril...          ",
    
  {
      /* ------------------------------------ */
      "A. Hay mil                              ",
      "B. Como miel                            ",
      "C. Aguas Mil.                           ",
      "D. Llueve mucho.                        ",
  },
    
  {
      /* ----- */
      "Hay mil  ",
      "Cómo miel",
      "Aguas Mil",
      "Llueve Mu",
  },
  },
  {
  /* Pregunta #15. */
  level_easy, answer_b,
    
  /* ------------------------------------ */
  "Termina el refrán: Perro ladrador...    ",
    
  {
      /* ------------------------------------ */
      "A. Es un amor.                          ",
      "B. Poco mordedor.                       ",
      "C. Vive  en un contenedor.              ",
      "D. Coge pulgas                          ",
  },
    
  {
      /* ----- */
      "Amor     ",
      "Poco Mord",
      "Contene. ",
      "Pulgas   ",
  },
  },
  {
  /* Pregunta #16. */
  level_easy, answer_d,
    
  /* ------------------------------------ */
  "¿Cuántos tentáculos tiene un pulpo?     ",
    
  {
      /* ------------------------------------ */
      "A. 4 Tentáculos.                        ",
      "B. 6 Tentáculos.                        ",
      "C. No tiene tentáculos                  ",
      "D. 8 Tentáculos                         ",
  },
    
  {
      /* ----- */
      "4        ",
      "6        ",
      "No tiene ",
      "8        ",
  },
  },
  {
  /* Pregunta #17. */
  level_easy, answer_a,
    
  /* ------------------------------------ */
  "¿Cuál es la capital de España?          ",
    
  {
      /* ------------------------------------ */
      "A. Madrid                               ",
      "B. Lisboa                               ",
      "C. París                                ",
      "D. Roma                                 ",
  },
    
  {
      /* ----- */
      "Madrid   ",
      "Lisboa   ",
      "París    ",
      "Roma     ",
  },
  },
  {
  /* Pregunta #18. */
  level_easy, answer_c,
    
  /* ------------------------------------ */
  "¿Qué es más grande 1 kg o 100 gramos?   ",
    
  {
      /* ------------------------------------ */
      "A. 100 Gramos.                          ",
      "B. Una abeja.                           ",
      "C. 1 Kilogramo                          ",
      "D. España siempre es más grande         ",
  },
    
  {
      /* ----- */
      "100 g    ",
      "abeja    ",
      "1 Kg     ",
      "España   ",
  },
  },
  {
  /* Pregunta #19. */
  level_easy, answer_b,
    
  /* ------------------------------------ */
  "¿Cuántos segundos son una hora?         ",
    
  {
      /* ------------------------------------ */
      "A. 60.                                  ",
      "B. 3600.                                ",
      "C. 120.                                 ",
      "D. 3000.                                ",
  },
    
  {
      /* ----- */
      "60       ",
      "3600     ",
      "120      ",
      "3000     ",
  },
  },
  {
  /* Pregunta #20. */
  level_easy, answer_d,
    
  /* ------------------------------------ */
  "¿Cómo se llama el gato cósmico?         ",
    
  {
      /* ------------------------------------ */
      "A. Dorami                               ",
      "B. Dorayaki                             ",
      "C. Nobita                               ",
      "D. Doraemon                             ",
  },
    
  {
      /* ----- */
      "Dorami   ",
      "Dorayaki ",
      "Nobita   ",
      "Doraemon ",
  },
  },
  {
  /* Pregunta #21. */
  level_easy, answer_a,
    
  /* ------------------------------------ */
  "¿Quién vive en la piña debajo del mar?  ",
    
  {
      /* ------------------------------------ */
      "A. Bob Esponja                          ",
      "B. Un político                          ",
      "C. Rafa Nadal                           ",
      "D. Ladybug                              ",
  },
    
  {
      /* ----- */
      "Bob Esp. ",
      "Político ",
      "Nadal    ",
      "Ladybug  ",
  },
  },












  {
  /* Pregunta #1. */
  level_medium, answer_a,
    
  /* ------------------------------------ */
  "¿Quién es Ibai?                         ",
    
  {
      /* ------------------------------------ */
      "A. Un streamer.                         ",
      "B. Un político.                         ",
      "C. El papa.                             ",
      "D. Mi padre.                            ",
  },
    
  {
      /* ----- */
      "Streamer ",
      "Político ",
      "El Papa  ",
      "Mi padre ",
  },
  },
  {
  /* Pregunta #2. */
  level_medium, answer_b,
    
  /* ------------------------------------ */
  "¿Cómo se llama el albúm de Quevedo 2023?",
    
  {
      /* ------------------------------------ */
      "A. Me falta algo.                       ",
      "B. Donde quiero estar.                  ",
      "C. Quedate.                             ",
      "D. Columbia.                            ",
  },
    
  {
      /* ----- */
      "Falt. Alg",
      "Dnd. Qui.",
      "Quedate  ",
      "Columbia ",
  },
  },
  {
  /* Pregunta #3. */
  level_medium, answer_c,
    
  /* ------------------------------------ */
  "¿Nombre del colegio de ‘Sex Education’? ",
    
  {
      /* ------------------------------------ */
      "A. Midtown.                             ",
      "B. Las encinas.                         ",
      "C. Moordale High.                       ",
      "D. High School                          ",
  },
    
  {
      /* ----- */
      "Midtown  ",
      "Encinas  ",
      "Moordale ",
      "High Sch.",
  },
  },
  {
  /* Pregunta #4. */
  level_medium, answer_d,
    
  /* ------------------------------------ */
  "Mujer que ha ganado 24 Grammy musicales?",
    
  {
      /* ------------------------------------ */
      "A. Aretha Franklin.                     ",
      "B. Alison Krauss.                       ",
      "C. Adele.                               ",
      "D. Beyonce                              ",
  },
    
  {
      /* ----- */
      "Aretha   ",
      "Alison   ",
      "Adele    ",
      "Beyonce  ",
  },
  },
  {
  /* Pregunta #5. */
  level_medium, answer_a,
    
  /* ------------------------------------ */
  "¿En qué año se estrenó Beetlejuice?     ",
    
  {
      /* ------------------------------------ */
      "A. 1988                                 ",
      "B. 1985                                 ",
      "C. 1990                                 ",
      "D. 1993                                 ",
  },
    
  {
      /* ----- */
      "1988     ",
      "1985     ",
      "1990     ",
      "1993     ",
  },
  },




  {
  /* Pregunta #6. */
  level_medium, answer_b,
    
  /* ------------------------------------ */
  "¿Qué fiesta se celebra en Cartagena?    ",
    
  {
      /* ------------------------------------ */
      "A. El cante de las minas.               ",
      "B. Carthagineses y romanos.             ",
      "C. Bando de la huerta.                  ",
      "D. Moros y cristianos.                  ",
  },
    
  {
      /* ----- */
      "Cant. Min",
      "Cart. Rom",
      "Bando    ",
      "Mo. Crist",
  },
  },
 {
  /* Pregunta #7. */
  level_medium, answer_c,
    
  /* ------------------------------------ */
  "¿Qué deporte es autóctono de Murcia?    ",
    
  {
      /* ------------------------------------ */
      "A. El fútbol.                           ",
      "B. La petanca.                          ",
      "C. Los bolos.                           ",
      "D. Tiro de Herradura.                   ",
  },
    
  {
      /* ----- */
      "Fútbol   ",
      "Petanca  ",
      "Bolos    ",
      "Herradura",
  },
  },


 {
  /* Pregunta #8. */
  level_hard, answer_d,
    
  /* ------------------------------------ */
  "¿Qué escritora famosa es de Cartagena?  ",
    
  {
      /* ------------------------------------ */
      "A. Rosalía de Castro.                   ",
      "B. Gabriela Mistral.                    ",
      "C. Clara Campoamor.                     ",
      "D. Carmen Conde.                        ",
  },
    
  {
      /* ----- */
      "Rosalía  ",
      "Gabriela ",
      "Cl. Campo",
      "Carmen C.",
  },
  },


 {
  /* Pregunta #9. */
  level_medium, answer_a,
    
  /* ------------------------------------ */
  "¿A qué grupo pertenecen: Tele5,FDF,La 4?",
    
  {
      /* ------------------------------------ */
      "A. Mediaset España.                     ",
      "B. Atresmedia.                          ",
      "C. Radio Televisión Española (RTVE).    ",
      "D. Grupo Planeta.                       ",
  },
    
  {
      /* ----- */
      "Mediaset ",
      "Atresmed.",
      "RTVE     ",
      "Planeta  ",
  },
  },


 {
  /* Pregunta #9. */
  level_medium, answer_b,
    
  /* ------------------------------------ */
  "¿Apellido de la reina Isabel II?        ",
    
  {
      /* ------------------------------------ */
      "A. Mcgregor.                            ",
      "B. Windsor.                             ",
      "C. Smith.                               ",
      "D. Brown.                               ",
  },
    
  {
      /* ----- */
      "Mcgregor ",
      "Windsor  ",
      "Smith    ",
      "Brown    ",
  },
  },


 {
  /* Pregunta #10. */
  level_medium, answer_c,
    
  /* ------------------------------------ */
  "¿Sistema Heliocéntrico fue creado por..?",
    
  {
      /* ------------------------------------ */
      "A. Kepler.                              ",
      "B. Newton.                              ",
      "C. Copérnico.                           ",
      "D. Bohr.                                ",
  },
    
  {
      /* ----- */
      "Kepler   ",
      "Newton   ",
      "Copérnico",
      "Bohr     ",
  },
  },


 {
  /* Pregunta #11. */
  level_hard, answer_d,
    
  /* ------------------------------------ */
  "¿Dónde se halla el bíceps crural?       ",
    
  {
      /* ------------------------------------ */
      "A. En los brazos.                       ",
      "B. En los pies.                         ",
      "C. En el cuello.                        ",
      "D. En las piernas.                      ",
  },
    
  {
      /* ----- */
      "Brazos   ",
      "Pies     ",
      "Cuello   ",
      "Piernas  ",
  },
  },


 {
  /* Pregunta #12. */
  level_hard, answer_a,
    
  /* ------------------------------------ */
  "¿Equipo de la premiere con más ligas?   ",
    
  {
      /* ------------------------------------ */
      "A. Manchester United.                   ",
      "B. Liverpool                            ",
      "C. Arsenal.                             ",
      "D. Everton.                             ",
  },
    
  {
      /* ----- */
      "Mach. Ut.",
      "Liverpool",
      "Arsenal  ",
      "Everton  ",
  },
  },


 {
  /* Pregunta #13. */
  level_medium, answer_b,
    
  /* ------------------------------------ */
  "¿País con más Eurocopas seguidas?       ",
    
  {
      /* ------------------------------------ */
      "A. Alemania.                            ",
      "B. España.                              ",
      "C. Francia.                             ",
      "D. Italia.                              ",
  },
    
  {
      /* ----- */
      "Alemania ",
      "España   ",
      "Francia  ",
      "Italia   ",
  },
  },


 {
  /* Pregunta #14. */
  level_medium, answer_c,
    
  /* ------------------------------------ */
  "¿En qué provincia está Trujillo?        ",
    
  {
      /* ------------------------------------ */
      "A. Córdoba.                             ",
      "B. Badajoz.                             ",
      "C. Cáceres.                             ",
      "D. Jaén.                                ",
  },
    
  {
      /* ----- */
      "Córdoba  ",
      "Badajoz  ",
      "Cáceres  ",
      "Jaén     ",
  },
  },


 {
  /* Pregunta #15. */
  level_medium, answer_d,
    
  /* ------------------------------------ */
  "¿Veces que ha ganado España Eurovisión? ",
    
  {
      /* ------------------------------------ */
      "A. 1 vez.                               ",
      "B. 4 veces.                             ",
      "C. 3 veces.                             ",
      "D. 2 veces.                             ",
  },
    
  {
      /* ----- */
      "1        ",
      "4        ",
      "3        ",
      "2        ",
  },
  },


 {
  /* Pregunta #16. */
  level_medium, answer_b,
    
  /* ------------------------------------ */
  "¿Año de la canción ‘Dame más gasolina’? ",
    
  {
      /* ------------------------------------ */
      "A. 2005.                                ",
      "B. 2010.                                ",
      "C. 2015.                                ",
      "D. 2017.                                ",
  },
    
  {
      /* ----- */
      "2005     ",
      "2010     ",
      "2015     ",
      "2017     ",
  },
  },


 {
  /* Pregunta #17. */
  level_medium, answer_a,
    
  /* ------------------------------------ */
  "¿Quién escribió ‘Cumbres borrascosas’?  ",
    
  {
      /* ------------------------------------ */
      "A. Emily Brontë.                        ",
      "B. Jane Austen.                         ",
      "C. Charlotte Brontë.                    ",
      "D. Virginia Woolf.                      ",
  },
    
  {
      /* ----- */
      "Emily    ",
      "Jane     ",
      "Charlotte",
      "Virginia ",
  },
  },


 {
  /* Pregunta #18. */
  level_medium, answer_c,
    
  /* ------------------------------------ */
  "¿Dónde nació la pizza?                  ",
    
  {
      /* ------------------------------------ */
      "A. Roma.                                ",
      "B. Florencia.                           ",
      "C. Nápoles.                             ",
      "D. Pisa.                                ",
  },
    
  {
      /* ----- */
      "Roma     ",
      "Florencia",
      "Nápoles  ",
      "Pisa     ",
  },
  },


 {
  /* Pregunta #19. */
  level_medium, answer_d,
    
  /* ------------------------------------ */
  "¿Cuánto duró la guerra de los 100 años? ",
    
  {
      /* ------------------------------------ */
      "A. 94 años                              ",
      "B. 100 años                             ",
      "C. 108 años.                            ",
      "D. 116 años.                            ",
  },
    
  {
      /* ----- */
      "94       ",
      "100      ",
      "108      ",
      "116      ",
  },
  },


 {
  /* Pregunta #20. */
  level_medium, answer_a,
    
  /* ------------------------------------ */
  "¿Quién fue “el manco de Lepanto”?       ",
    
  {
      /* ------------------------------------ */
      "A. Miguel de Cervantes.                 ",
      "B. Vincent Van Gogh.                    ",
      "C. Salvador Dalí.                       ",
      "D. Antonio Machado.                     ",
  },
    
  {
      /* ----- */
      "Cervantes",
      "Van Gogh ",
      "Dalí     ",
      "Machado  ",
  },
  },
};

const uint trivia_count_a = sizeof(trivia_set_a) / sizeof(trivia_t);
const uint trivia_count_b = sizeof(trivia_set_b) / sizeof(trivia_t);
