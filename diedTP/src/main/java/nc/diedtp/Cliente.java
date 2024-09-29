/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package nc.diedtp;

public class Cliente {
    private static int next_id = 0;
    private int id;
    private int cuit;
    private String email;
    private String direccion;
    private Coordenada coordenadas;
    private String nombre;
  
    public Cliente(){} //constructor generico para poder instanciar un cliente sin parametros
    public Cliente(String nombre, int cuit, String email, String direccion, double latitud, double longitud ){
        this.id = next_id;
        ++next_id;
        this.cuit = cuit;
        this.email = email;
        this.direccion = direccion;
        this.coordenadas = new Coordenada(latitud, longitud);
        this.nombre = nombre;
    }
    public Coordenada getCoordenada(){
        return this.coordenadas;
    }
    public String getDireccion(){
        return direccion;
    }
    public int getId()
   {
       return id;
   }
   public int getCuit()
   {
       return cuit;
   }
     public String getEmail(){
        return email;
    }
    public String getNombre(){
        return nombre;
    }
    
    @Override
    public String toString(){
        return "Nombre: "+nombre+"\nId: "+Integer.toString(id)+"\nCuit: "
                +Integer.toString(cuit)+"\nEmail: "+email+"\nDireccion: "+direccion;
    }
     
}
