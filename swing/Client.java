//
// Client Java pour communiquer avec le Serveur C++
// eric lecolinet - telecom paristech - 2015
//

import java.io.*;
import java.net.*;

public class Client
{
    private static final long serialVersionUID = 1L;
    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;
    private Socket sock;
    private BufferedReader input;
    private BufferedWriter output;
    // Port, host used (if not default)
    private String host;
    private int port;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    ///
    /// Lit une requete depuis le Terminal, envoie cette requete au serveur,
    /// recupere sa reponse et l'affiche sur le Terminal.
    /// Noter que le programme bloque si le serveur ne repond pas.
    ///

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    ///
    /// Initialise la connexion.
    /// Renvoie une exception en cas d'erreur.
    ///
    public Client(String host, int port) throws UnknownHostException, IOException {
        try {
            sock = new java.net.Socket(host, port);
        }
        catch (java.net.UnknownHostException e) {
            throw new UnknownHostException("Client: Couldn't find host "+host+":"+port);
        }
        catch (java.io.IOException e) {
            throw new IOException("Client: Couldn't reach host "+host+":"+port);
        }

        try {
            input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
            output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
        }
        catch (java.io.IOException e) {
            System.err.println("Client: Couldn't open input or output streams");
            throw e;
        }

        this.host = host;
        this.port = port;
    }

    public Client() throws UnknownHostException, IOException {
        this(DEFAULT_HOST, DEFAULT_PORT);
    }

    public int getPort() {
        return port;
    }

    public String getHost() {
        return host;
    }
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    ///
    /// Envoie une requete au server et retourne sa reponse.
    /// Noter que la methode bloque si le serveur ne repond pas.
    ///
    public String send(String request) {
        // Envoyer la requete au serveur
        try {
            request += "\n";  // ajouter le separateur de lignes
            output.write(request, 0, request.length());
            output.flush();
        }
        catch (java.io.IOException e) {
            System.err.println("Client: Couldn't send message: " + e);
            return null;
        }

        // Recuperer le resultat envoye par le serveur
        try {
            return input.readLine();
        }
        catch (java.io.IOException e) {
            System.err.println("Client: Couldn't receive message: " + e);
            return null;
        }
    }
}


