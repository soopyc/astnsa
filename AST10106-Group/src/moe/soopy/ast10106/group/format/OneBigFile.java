/**
 * The one big file format
 * 
 * @author H10007740, H10007792, H10008060
 */
package moe.soopy.ast10106.group.format;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.time.LocalDate;
import java.util.ArrayList;

public class OneBigFile {
	final static String SEPARATOR = "---";
	public Metadata metadata;
	public ArrayList<Record> records;

	/**
	 * Initializes the class. You might want to use OneBigFile.parse or
	 * OneBigFile.load instead.
	 *
	 * @param metadata
	 * @param records
	 */
	public OneBigFile(Metadata metadata, ArrayList<Record> records) {
		this.metadata = metadata;
		if (records == null) {
			this.records = new ArrayList<Record>();
		} else {
			this.records = records;
		}
	}

	/**
	 * parse the entire file into a object oriented format.
	 *
	 * @param toBeParsed the string to be parsed
	 * @return parsed data as a OneBigFile object
	 */
	public static OneBigFile parse(String toBeParsed) {
		String[] split = toBeParsed.split(SEPARATOR);
		Metadata metadata = Metadata.parse(split[0].strip()); // metadata field, before dashes

		// iterate through each line after the dashes, wherein each line is a record.
		// ignore lines in which there are parsing errors.
		String[] rawRecords = split[1].strip().split("\n");
		ArrayList<Record> records = new ArrayList<Record>();
		for (String rawRecord : rawRecords) {
			try {
				// parse each record into a Record type.
				if (rawRecord.strip().equals(""))
					continue; // skip empty lines without errors.
				records.add(Record.parse(rawRecord.strip()));
			} catch (Exception e) {
				System.err.println("WARNING: Could not parse record: " + rawRecord);
				System.err.println("Error: " + e.toString());
			}
		}

		// finally return the constructed object
		return new OneBigFile(metadata, records);
	}

	// serialize the format
	public String toString() {
		String metadata = this.metadata.toString();
		String records = "";
		for (Record record : this.records) {
			records += record.toString() + "\n";
		}
		return metadata + "\n" + SEPARATOR + "\n" + records;
	}

	/**
	 * Add a new record to the records list.
	 *
	 * @param record the record to be added.
	 */
	public void addRecord(Record record) {
		this.records.add(record);
		this.metadata.update();
	}

	/**
	 * Get a list of records by income/expense type.
	 *
	 * @param type the type to get records for.
	 * @return a list of records matching the requested type.
	 */
	public ArrayList<Record> getRecordsByType(String type) {
		ArrayList<Record> records = new ArrayList<Record>();
		for (Record record : this.records) {
			if (record.type.equals(type)) {
				records.add(record);
			}
		}
		return records;
	}

	/**
	 * Get a singular record based on the ID prefix.
	 * @param id the id prefix
	 * @return a record or null if none are found.
	 */
	public Record getRecordByID(String id) {
		for (Record record : this.records) {
			if (record.id.startsWith(id))
				return record;
		}
		return null;
	}

	/**
	 * Get total amount of money from records by type.
	 *
	 * @param type the record type to search for
	 * @return the total recorded amount of the requested type.
	 */
	public double getAmountByType(String type) {
		double amounts = 0.0;
		for (Record record : this.getRecordsByType(type))
			amounts += record.amount;
		return amounts;
	}

	/**
	 * Get the earliest recorded date of a specific record type.
	 *
	 * @param type the record type to search for
	 * @return the earliest appeared date of the type.
	 */
	public LocalDate getEarliestDateByType(String type) {
		LocalDate date = LocalDate.now();
		for (Record currentRecord : this.getRecordsByType(type)) {
			if (currentRecord.date.isBefore(date)) {
				date = currentRecord.date;
			}
		}
		return date;
	}

	/**
	 * Load data from a file to the OneBigFile format.
	 *
	 * References:
	 * https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/nio/file/Files.html#readString(java.nio.file.Path,java.nio.charset.Charset)
	 * https://stackoverflow.com/a/326440
	 *
	 * @param filename The filename to load the file from
	 * @return the parsed and loaded OneBigFile format
	 * @throws IOException
	 */
	static public OneBigFile load(String filename) throws IOException {
		String data = Files.readString(Paths.get(filename));
		return OneBigFile.parse(data);
	}

	/**
	 * Flush and write the data to a file.
	 *
	 * @param filename The filename to write the file to.
	 * @throws IOException
	 */
	public void write(String filename) throws IOException {
		Files.writeString(Paths.get(filename), this.toString());
	}
}
