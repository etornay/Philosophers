<h1>1. Descripción general</h1>

_Aquí tienes una lista de cosas que deberías conocer si quieres superar este proyecto:_

• Uno o más filósofos se sientan en una mesa redonda.
En el centro de la mesa se encuentra un gran bol de espaguetis.

• Los filósofos solo pueden comer, pensar, o dormir.
Mientras están comiendo, no pueden pensar ni dormir;
Mientras están pensando, no pueden dormir ni comer;
Y, por supuesto, mientras están durmiendo, no pueden comer ni pensar.

• También hay tenedores en la mesa, tantos tenedores como filósofos.

• Porque coger y comer espaguetis con un solo tenedor puede ser incomodo, los filósofos deben tomar el tenedor de la derecha y el de la izquierda, uno en cada mano.

• Cuándo un filósofo termine de comer, dejará los tenedores en la mesa e inmediatamente empezará a dormir. Una vez se despierte, empezará a pensar nuevamente.
La simulación se detendrá cuando un filósofo muere por inanición.

• Todos los filósofos necesitan comer y nunca deben morir de hambre.

• Los filósofos no hablan entre ellos.

• Los filósofos no saben si otro filósofo va a morir.

• ¡No debería hacer falta decir que todos deben evitar morir!

<h1>2. Instrucciones generales</h1>

_Deberás escribir un programa para la parte obligatoria y otro para la parte bonus (Solo
si decides hacer la parte bonus). Ambas tienen que cumplir con las siguientes reglas:_

• ¡Las variables globales están prohibidas!

• Tu(s) programa(s) debe(n) aceptar los siguientes argumentos:
**number_of_philosophers**, **time_to_die**, **time_to_eat**, **time_to_sleep**,
**number_of_times_each_philosopher_must_eat**,

**◦ number_of_philosophers: es el número de filósofos, pero también el número
de tenedores.**

**◦ time_to_die (en milisegundos): si un filósofo no empieza a comer en time_to_die
milisegundos desde el comienzo de su ultima comida o desde el principio de la
simulación, este morirá.**

**◦ time_to_eat (en milisegundos): es el tiempo que tiene un filósofo para comer.
Durante ese tiempo, tendrá los tenedores ocupados.**

**◦ time_to_sleep (en milisegundos): es el tiempo que tiene un filósofo para
dormir.**

**◦ number_of_times_each_philosopher_must_eat (argumento opcional): si todos los filósofos comen al menos number_of_times_each_philosopher_must_eat
veces, la simulación se detendrá. Si no se especifica, la simulación se detendrá
con la muerte de un filósofo.**

• Cada filósofo tendrá asignado un número del 1 al number_of_philosophers.

• El filósofo número 1 se sentará al lado del filósofo número number_of_philosophers.
Cualquier otro filósofo número N se sentarán entre el filósofo número N - 1 y el filósofo
número N + 1.

_Los logs de tu programa:_

• Cualquier cambio de estado de un filósofo debe tener el siguiente formato:

**◦ timestamp_in_ms X has taken a fork**

**◦ timestamp_in_ms X is eating**

**◦ timestamp_in_ms X is sleeping**

**◦ timestamp_in_ms X is thinking**

**◦ timestamp_in_ms X died**

Reemplaza timestamp_in_ms con la marca de tiempo actual en milisegundos
y X con el numero del filósofo.

• El estado impreso no debe estar roto o alterado por el estado de otros filósofos

• No puedes tener más de 10ms entre la muerte de un filósofo y el momento en el que
imprimes su muerte.

• Te recuerdo, los filósofos deben evitar morir.

<h1>3. Parte obligatoria</h1>

_Las reglas específicas para la parte obligatoria son:_

• Cada filósofo debe ser un hilo.

• Hay un tenedor entre cada filósofo. por lo tanto, si hay varios filósofos, cada filósofo
debe tener un tenedor a su izquierda y otro a su derecha. si solo hay un filósofo,
solo habrá un tenedor en la mesa.

• Para prevenir que los filósofos dupliquen los tenedores, deberás proteger los estados
de los tenedores con un mutex por cada uno de ellos.
