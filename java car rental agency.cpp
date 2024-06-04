import.java.util.scanner

public class Car {

    private String make;

    private String model;

    private String licensePlate;

    private boolean isRented;



    public Car(String make, String model, String licensePlate) {

        this.make = make;

        this.model = model;

        this.licensePlate = licensePlate;

        this.isRented = false;

    }



    public String getMake() {

        return make;

    }



    public String getModel() {

        return model;

    }



    public String getLicensePlate() {

        return licensePlate;

    }



    public boolean isRented() {

        return isRented;

    }



    public void rentCar() {

        if (!isRented) {

            this.isRented = true;

        } else {

            System.out.println("Car is already rented.");

        }

    }



    public void returnCar() {

        if (isRented) {

            this.isRented = false;

        } else {

            System.out.println("Car was not rented.");

        }

    }



    @Override

    public String toString() {

        return "Car{" +

                "make='" + make + '\'' +

                ", model='" + model + '\'' +

                ", licensePlate='" + licensePlate + '\'' +

                ", isRented=" + isRented +

                '}';

    }

}



public class Customer {

    private String name;

    private String driverLicense;



    public Customer(String name, String driverLicense) {

        this.name = name;

        this.driverLicense = driverLicense;

    }



    public String getName() {

        return name;

    }



    public String getDriverLicense() {

        return driverLicense;

    }



    @Override

    public String toString() {

        return "Customer{" +

                "name='" + name + '\'' +

                ", driverLicense='" + driverLicense + '\'' +

                '}';

    }

}



import java.util.ArrayList;

import java.util.List;



public class RentalAgency {

    private List<Car> cars;

    private List<Customer> customers;



    public RentalAgency() {

        this.cars = new ArrayList<>();

        this.customers = new ArrayList<>();

    }



    public void addCar(Car car) {

        cars.add(car);

    }



    public void addCustomer(Customer customer) {

        customers.add(customer);

    }



    public Car findCarByLicensePlate(String licensePlate) {

        for (Car car : cars) {

            if (car.getLicensePlate().equals(licensePlate)) {

                return car;

            }

        }

        return null;

    }



    public Customer findCustomerByName(String name) {

        for (Customer customer : customers) {

            if (customer.getName().equals(name)) {

                return customer;

            }

        }

        return null;

    }



    public void rentCar(String licensePlate, String customerName) {

        Car car = findCarByLicensePlate(licensePlate);

        Customer customer = findCustomerByName(customerName);



        if (car != null && customer != null && !car.isRented()) {

            car.rentCar();

            System.out.println(customer.getName() + " rented " + car.getMake() + " " + car.getModel());

        } else {

            System.out.println("Rental transaction failed.");

        }

    }



    public void returnCar(String licensePlate, String customerName) {

        Car car = findCarByLicensePlate(licensePlate);

        Customer customer = findCustomerByName(customerName);



        if (car != null && customer != null && car.isRented()) {

            car.returnCar();

            System.out.println(customer.getName() + " returned " + car.getMake() + " " + car.getModel());

        } else {

            System.out.println("Return transaction failed.");

        }

    }



    public static void main(String[] args) {

        RentalAgency agency = new RentalAgency();



        Car car1 = new Car("mazda", "Corolla", "ABC123");

        Car car2 = new Car("wish", "Civic", "XYZ789");

        agency.addCar(car1);

        agency.addCar(car2);



        Customer customer1 = new Customer("Allan", "D1234567");

        Customer customer2 = new Customer("maina", "D7654321");

        agency.addCustomer(customer1);

        agency.addCustomer(customer2);



        agency.rentCar("ABC123", "Allan");

        agency.returnCar("ABC123", "Allan");



        agency.rentCar("XYZ789", "maina");

        agency.returnCar("XYZ789", "maina");

    }

}





