È necessario inserire la directory di pacs-examples nel makefile.

Il programma tramite l'architettura a plugins implementa tre schemi risolutivi: bisezione, secante e Broyden.
L'idea della classe FunctionRtoR è quella di modellizzare una funzione scalare in una variabile ed implementare metodi utili per calcolare lo zero della funzione e stamparlo. I metodi della classe sono:
• setSolver che permette di scegliere un metodo numerico tra i metodi caricati nella solver factory, controllando se il metodo è presente.
• setOption permette di impostare i parametri associati a solver e verifica che sia già stato scelto un metodo. 
• print stampa il risultato se l'algoritmo ha converso, altrimenti comunica che non ha converso.

L'architettura a plugin utilizza una object factory implementata attraverso le mappe in quanto tutti i metodi risolutivi vengono costruiti nello stesso modo, cioè con un unico argomento FuncionType.

Il focus di questa challenge l'ho posto molto sull'architettura a plugin piuttosto che sugli altri aspetti che hanno vario margine di miglioramento, questo perché dato che nella prima challenge mi sono concentrato sulle funzionalità e sulla esperienza utente, in quest'ultima mi interessava approfondire maggiormente questo lato, anche se purtroppo ho trascurato altri aspetti.